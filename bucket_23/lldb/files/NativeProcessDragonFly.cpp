//===-- NativeProcessDragonFly.cpp ------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "NativeProcessDragonFly.h"

// clang-format off
#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/sysctl.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <machine/elf.h>
// clang-format on

#include "Plugins/Process/POSIX/ProcessPOSIXLog.h"
#include "lldb/Host/HostProcess.h"
#include "lldb/Host/posix/ProcessLauncherPosixFork.h"
#include "lldb/Target/Process.h"
#include "lldb/Utility/State.h"
#include "llvm/Support/Errno.h"

using namespace lldb;
using namespace lldb_private;
using namespace lldb_private::process_dragonfly;
using namespace llvm;

// Simple helper function to ensure flags are enabled on the given file
// descriptor.
static Status EnsureFDFlags(int fd, int flags) {
  Status error;

  int status = fcntl(fd, F_GETFL);
  if (status == -1) {
    error.SetErrorToErrno();
    return error;
  }

  if (fcntl(fd, F_SETFL, status | flags) == -1) {
    error.SetErrorToErrno();
    return error;
  }

  return error;
}

static Status CanTrace() {
  int proc_debug, ret;
  size_t len = sizeof(proc_debug);
  ret = ::sysctlbyname("security.bsd.unprivileged_proc_debug", &proc_debug,
                       &len, nullptr, 0);
  if (ret != 0)
    return Status("sysctlbyname() security.bsd.unprivileged_proc_debug failed");

  if (proc_debug < 1)
    return Status(
        "process debug disabled by security.bsd.unprivileged_proc_debug oid");

  return {};
}

// Public Static Methods

llvm::Expected<std::unique_ptr<NativeProcessProtocol>>
NativeProcessDragonFly::Manager::Launch(ProcessLaunchInfo &launch_info,
                                      NativeDelegate &native_delegate) {
  Log *log = GetLog(POSIXLog::Process);
  Status status;

  ::pid_t pid = ProcessLauncherPosixFork()
                    .LaunchProcess(launch_info, status)
                    .GetProcessId();
  LLDB_LOG(log, "pid = {0:x}", pid);
  if (status.Fail()) {
    LLDB_LOG(log, "failed to launch process: {0}", status);
    auto error = CanTrace();
    if (error.Fail())
      return error.ToError();
    return status.ToError();
  }

  // Wait for the child process to trap on its call to execve.
  int wstatus;
  ::pid_t wpid = llvm::sys::RetryAfterSignal(-1, ::waitpid, pid, &wstatus, 0);
  assert(wpid == pid);
  UNUSED_IF_ASSERT_DISABLED(wpid);
  if (!WIFSTOPPED(wstatus)) {
    LLDB_LOG(log, "Could not sync with inferior process: wstatus={1}",
             WaitStatus::Decode(wstatus));
    return llvm::make_error<StringError>("Could not sync with inferior process",
                                         llvm::inconvertibleErrorCode());
  }
  LLDB_LOG(log, "inferior started, now in stopped state");

  ProcessInstanceInfo Info;
  if (!Host::GetProcessInfo(pid, Info)) {
    return llvm::make_error<StringError>("Cannot get process architecture",
                                         llvm::inconvertibleErrorCode());
  }

  // Set the architecture to the exe architecture.
  LLDB_LOG(log, "pid = {0:x}, detected architecture {1}", pid,
           Info.GetArchitecture().GetArchitectureName());

  std::unique_ptr<NativeProcessDragonFly> process_up(new NativeProcessDragonFly(
      pid, launch_info.GetPTY().ReleasePrimaryFileDescriptor(), native_delegate,
      Info.GetArchitecture(), m_mainloop));

  status = process_up->SetupTrace();
  if (status.Fail())
    return status.ToError();

  for (const auto &thread : process_up->m_threads)
    static_cast<NativeThreadDragonFly &>(*thread).SetStoppedBySignal(SIGSTOP);
  process_up->SetState(StateType::eStateStopped, false);

  return std::move(process_up);
}

llvm::Expected<std::unique_ptr<NativeProcessProtocol>>
NativeProcessDragonFly::Manager::Attach(
    lldb::pid_t pid, NativeProcessProtocol::NativeDelegate &native_delegate) {
  Log *log = GetLog(POSIXLog::Process);
  LLDB_LOG(log, "pid = {0:x}", pid);

  // Retrieve the architecture for the running process.
  ProcessInstanceInfo Info;
  if (!Host::GetProcessInfo(pid, Info)) {
    return llvm::make_error<StringError>("Cannot get process architecture",
                                         llvm::inconvertibleErrorCode());
  }

  std::unique_ptr<NativeProcessDragonFly> process_up(new NativeProcessDragonFly(
      pid, -1, native_delegate, Info.GetArchitecture(), m_mainloop));

  Status status = process_up->Attach();
  if (!status.Success())
    return status.ToError();

  return std::move(process_up);
}

NativeProcessDragonFly::Extension
NativeProcessDragonFly::Manager::GetSupportedExtensions() const {
  return
#if defined(PT_COREDUMP)
      Extension::savecore |
#endif
      Extension::multiprocess | Extension::fork | Extension::vfork |
      Extension::pass_signals | Extension::auxv | Extension::libraries_svr4 |
      Extension::siginfo_read;
}

// Public Instance Methods

NativeProcessDragonFly::NativeProcessDragonFly(::pid_t pid, int terminal_fd,
                                           NativeDelegate &delegate,
                                           const ArchSpec &arch,
                                           MainLoop &mainloop)
    : NativeProcessELF(pid, terminal_fd, delegate), m_arch(arch),
      m_main_loop(mainloop) {
  if (m_terminal_fd != -1) {
    Status status = EnsureFDFlags(m_terminal_fd, O_NONBLOCK);
    assert(status.Success());
  }

  Status status;
  m_sigchld_handle = mainloop.RegisterSignal(
      SIGCHLD, [this](MainLoopBase &) { SigchldHandler(); }, status);
  assert(m_sigchld_handle && status.Success());
}

// Handles all waitpid events from the inferior process.
void NativeProcessDragonFly::MonitorCallback(lldb::pid_t pid, int signal) {
  switch (signal) {
  case SIGTRAP:
    return MonitorSIGTRAP(pid);
  case SIGSTOP:
    return MonitorSIGSTOP(pid);
  default:
    return MonitorSignal(pid, signal);
  }
}

void NativeProcessDragonFly::MonitorExited(lldb::pid_t pid, WaitStatus status) {
  Log *log = GetLog(POSIXLog::Process);

  LLDB_LOG(log, "got exit signal({0}) , pid = {1}", status, pid);

  /* Stop Tracking All Threads attached to Process */
  m_threads.clear();

  SetExitStatus(status, true);

  // Notify delegate that our process has exited.
  SetState(StateType::eStateExited, true);
}

void NativeProcessDragonFly::MonitorSIGSTOP(lldb::pid_t pid) {
  /* Stop all Threads attached to Process */
  for (const auto &thread : m_threads) {
    static_cast<NativeThreadDragonFly &>(*thread).SetStoppedBySignal(SIGSTOP,
                                                                   nullptr);
  }
  SetState(StateType::eStateStopped, true);
}

void NativeProcessDragonFly::MonitorSIGTRAP(lldb::pid_t pid) {
  Log *log = GetLog(POSIXLog::Process);

  // DragonFly ptrace can't query kernel threads for signal information
  LLDB_LOG(log, "SIGTRAP, passing to generic handler");
  MonitorSignal(pid, SIGTRAP);
}

void NativeProcessDragonFly::MonitorSignal(lldb::pid_t pid, int signal) {
  Log *log = GetLog(POSIXLog::Process);
  
  // DragonFly ptrace can't query kernel threads for signal information
  LLDB_LOG(log, "SIGNAL {0} received, marked stopped", signal);
  SetState(StateType::eStateStopped, true);
}

Status NativeProcessDragonFly::PtraceWrapper(int req, lldb::pid_t pid, void *addr,
                                           int data, int *result) {
  Log *log = GetLog(POSIXLog::Ptrace);
  Status error;
  int ret;

  errno = 0;
  ret =
      ptrace(req, static_cast<::pid_t>(pid), static_cast<caddr_t>(addr), data);

  if (ret == -1) {
    error = CanTrace();
    if (error.Success())
      error.SetErrorToErrno();
  }

  if (result)
    *result = ret;

  LLDB_LOG(log, "ptrace({0}, {1}, {2}, {3})={4:x}", req, pid, addr, data, ret);

  if (error.Fail())
    LLDB_LOG(log, "ptrace() failed: {0}", error);

  return error;
}

llvm::Expected<llvm::ArrayRef<uint8_t>>
NativeProcessDragonFly::GetSoftwareBreakpointTrapOpcode(size_t size_hint) {
  static const uint8_t g_arm_opcode[] = {0xfe, 0xde, 0xff, 0xe7};
  static const uint8_t g_thumb_opcode[] = {0x01, 0xde};

  switch (GetArchitecture().GetMachine()) {
  case llvm::Triple::arm:
    switch (size_hint) {
    case 2:
      return llvm::ArrayRef(g_thumb_opcode);
    case 4:
      return llvm::ArrayRef(g_arm_opcode);
    default:
      return llvm::createStringError(llvm::inconvertibleErrorCode(),
                                     "Unrecognised trap opcode size hint!");
    }
  default:
    return NativeProcessProtocol::GetSoftwareBreakpointTrapOpcode(size_hint);
  }
}

Status NativeProcessDragonFly::Resume(const ResumeActionList &resume_actions) {
  Log *log = GetLog(POSIXLog::Process);
  LLDB_LOG(log, "pid {0}", GetID());

  Status ret;

  int signal = 0;
  for (const auto &abs_thread : m_threads) {
    assert(abs_thread && "thread list should not contain NULL threads");
    NativeThreadDragonFly &thread =
        static_cast<NativeThreadDragonFly &>(*abs_thread);

    const ResumeAction *action =
        resume_actions.GetActionForThread(thread.GetID(), true);
    // we need to explicit issue suspend requests, so it is simpler to map it
    // into proper action
    ResumeAction suspend_action{thread.GetID(), eStateSuspended,
                                LLDB_INVALID_SIGNAL_NUMBER};

    if (action == nullptr) {
      LLDB_LOG(log, "no action specified for pid {0} tid {1}", GetID(),
               thread.GetID());
      action = &suspend_action;
    }

    LLDB_LOG(
        log,
        "processing resume action state {0} signal {1} for pid {2} tid {3}",
        action->state, action->signal, GetID(), thread.GetID());

    switch (action->state) {
    case eStateRunning:
      ret = thread.Resume();
      break;
    case eStateStepping:
      ret = thread.SingleStep();
      break;
    case eStateSuspended:
    case eStateStopped:
      if (action->signal != LLDB_INVALID_SIGNAL_NUMBER)
        return Status("Passing signal to suspended thread unsupported");

      ret = thread.Suspend();
      break;

    default:
      return Status(
          "NativeProcessDragonFly::%s (): unexpected state %s specified "
          "for pid %" PRIu64 ", tid %" PRIu64,
          __FUNCTION__, StateAsCString(action->state), GetID(), thread.GetID());
    }

    if (!ret.Success())
      return ret;
    if (action->signal != LLDB_INVALID_SIGNAL_NUMBER)
      signal = action->signal;
  }

  ret =
      PtraceWrapper(PT_CONTINUE, GetID(), reinterpret_cast<void *>(1), signal);
  if (ret.Success())
    SetState(eStateRunning, true);
  return ret;
}

Status NativeProcessDragonFly::Halt() {
  Status error;

  // Do not try to stop a process that's already stopped, this may cause
  // the SIGSTOP to get queued and stop the process again once resumed.
  if (StateIsStoppedState(m_state, false))
    return error;
  if (kill(GetID(), SIGSTOP) != 0)
    error.SetErrorToErrno();
  return error;
}

Status NativeProcessDragonFly::Detach() {
  Status error;

  // Stop monitoring the inferior.
  m_sigchld_handle.reset();

  // Tell ptrace to detach from the process.
  if (GetID() == LLDB_INVALID_PROCESS_ID)
    return error;

  return PtraceWrapper(PT_DETACH, GetID());
}

Status NativeProcessDragonFly::Signal(int signo) {
  Status error;

  if (kill(GetID(), signo))
    error.SetErrorToErrno();

  return error;
}

Status NativeProcessDragonFly::Interrupt() { return Halt(); }

Status NativeProcessDragonFly::Kill() {
  Log *log = GetLog(POSIXLog::Process);
  LLDB_LOG(log, "pid {0}", GetID());

  Status error;

  switch (m_state) {
  case StateType::eStateInvalid:
  case StateType::eStateExited:
  case StateType::eStateCrashed:
  case StateType::eStateDetached:
  case StateType::eStateUnloaded:
    // Nothing to do - the process is already dead.
    LLDB_LOG(log, "ignored for PID {0} due to current state: {1}", GetID(),
             StateAsCString(m_state));
    return error;

  case StateType::eStateConnected:
  case StateType::eStateAttaching:
  case StateType::eStateLaunching:
  case StateType::eStateStopped:
  case StateType::eStateRunning:
  case StateType::eStateStepping:
  case StateType::eStateSuspended:
    // We can try to kill a process in these states.
    break;
  }

  return PtraceWrapper(PT_KILL, m_pid);
}

Status NativeProcessDragonFly::GetMemoryRegionInfo(lldb::addr_t load_addr,
                                                 MemoryRegionInfo &range_info) {

  if (m_supports_mem_region == LazyBool::eLazyBoolNo) {
    // We're done.
    return Status("unsupported");
  }

  Status error = PopulateMemoryRegionCache();
  if (error.Fail()) {
    return error;
  }

  lldb::addr_t prev_base_address = 0;
  // FIXME start by finding the last region that is <= target address using
  // binary search.  Data is sorted.
  // There can be a ton of regions on pthreads apps with lots of threads.
  for (auto it = m_mem_region_cache.begin(); it != m_mem_region_cache.end();
       ++it) {
    MemoryRegionInfo &proc_entry_info = it->first;
    // Sanity check assumption that memory map entries are ascending.
    assert((proc_entry_info.GetRange().GetRangeBase() >= prev_base_address) &&
           "descending memory map entries detected, unexpected");
    prev_base_address = proc_entry_info.GetRange().GetRangeBase();
    UNUSED_IF_ASSERT_DISABLED(prev_base_address);
    // If the target address comes before this entry, indicate distance to next
    // region.
    if (load_addr < proc_entry_info.GetRange().GetRangeBase()) {
      range_info.GetRange().SetRangeBase(load_addr);
      range_info.GetRange().SetByteSize(
          proc_entry_info.GetRange().GetRangeBase() - load_addr);
      range_info.SetReadable(MemoryRegionInfo::OptionalBool::eNo);
      range_info.SetWritable(MemoryRegionInfo::OptionalBool::eNo);
      range_info.SetExecutable(MemoryRegionInfo::OptionalBool::eNo);
      range_info.SetMapped(MemoryRegionInfo::OptionalBool::eNo);
      return error;
    } else if (proc_entry_info.GetRange().Contains(load_addr)) {
      // The target address is within the memory region we're processing here.
      range_info = proc_entry_info;
      return error;
    }
    // The target memory address comes somewhere after the region we just
    // parsed.
  }
  // If we made it here, we didn't find an entry that contained the given
  // address. Return the load_addr as start and the amount of bytes betwwen
  // load address and the end of the memory as size.
  range_info.GetRange().SetRangeBase(load_addr);
  range_info.GetRange().SetRangeEnd(LLDB_INVALID_ADDRESS);
  range_info.SetReadable(MemoryRegionInfo::OptionalBool::eNo);
  range_info.SetWritable(MemoryRegionInfo::OptionalBool::eNo);
  range_info.SetExecutable(MemoryRegionInfo::OptionalBool::eNo);
  range_info.SetMapped(MemoryRegionInfo::OptionalBool::eNo);
  return error;
}

Status NativeProcessDragonFly::PopulateMemoryRegionCache() {
  Log *log = GetLog(POSIXLog::Process);
  // If our cache is empty, pull the latest.  There should always be at least
  // one memory region if memory region handling is supported.
  if (!m_mem_region_cache.empty()) {
    LLDB_LOG(log, "reusing {0} cached memory region entries",
             m_mem_region_cache.size());
    return Status();
  }

  m_supports_mem_region = LazyBool::eLazyBoolNo;
  return Status("PopulateMemoryRegionCache Unimplemented");
}

size_t NativeProcessDragonFly::UpdateThreads() { return m_threads.size(); }

Status NativeProcessDragonFly::SetBreakpoint(lldb::addr_t addr, uint32_t size,
                                           bool hardware) {
  if (hardware)
    return SetHardwareBreakpoint(addr, size);
  return SetSoftwareBreakpoint(addr, size);
}

Status NativeProcessDragonFly::GetLoadedModuleFileSpec(const char *module_path,
                                                     FileSpec &file_spec) {
  Status error = PopulateMemoryRegionCache();
  if (error.Fail()) {
    auto status = CanTrace();
    if (status.Fail())
      return status;
    return error;
  }

  FileSpec module_file_spec(module_path);
  FileSystem::Instance().Resolve(module_file_spec);

  file_spec.Clear();
  for (const auto &it : m_mem_region_cache) {
    if (it.second.GetFilename() == module_file_spec.GetFilename()) {
      file_spec = it.second;
      return Status();
    }
  }
  return Status("Module file (%s) not found in process' memory map!",
                module_file_spec.GetFilename().AsCString());
}

Status
NativeProcessDragonFly::GetFileLoadAddress(const llvm::StringRef &file_name,
                                         lldb::addr_t &load_addr) {
  load_addr = LLDB_INVALID_ADDRESS;
  Status error = PopulateMemoryRegionCache();
  if (error.Fail()) {
    auto status = CanTrace();
    if (status.Fail())
      return status;
    return error;
  }

  FileSpec file(file_name);
  for (const auto &it : m_mem_region_cache) {
    if (it.second == file) {
      load_addr = it.first.GetRange().GetRangeBase();
      return Status();
    }
  }
  return Status("No load address found for file %s.", file_name.str().c_str());
}

void NativeProcessDragonFly::SigchldHandler() {
  Log *log = GetLog(POSIXLog::Process);
  int status;
  ::pid_t wait_pid =
      llvm::sys::RetryAfterSignal(-1, waitpid, GetID(), &status, WNOHANG);

  if (wait_pid == 0)
    return;

  if (wait_pid == -1) {
    Status error(errno, eErrorTypePOSIX);
    LLDB_LOG(log, "waitpid ({0}, &status, _) failed: {1}", GetID(), error);
    return;
  }

  WaitStatus wait_status = WaitStatus::Decode(status);
  bool exited = wait_status.type == WaitStatus::Exit ||
                (wait_status.type == WaitStatus::Signal &&
                 wait_pid == static_cast<::pid_t>(GetID()));

  LLDB_LOG(log,
           "waitpid ({0}, &status, _) => pid = {1}, status = {2}, exited = {3}",
           GetID(), wait_pid, status, exited);

  if (exited)
    MonitorExited(wait_pid, wait_status);
  else {
    assert(wait_status.type == WaitStatus::Stop);
    MonitorCallback(wait_pid, wait_status.status);
  }
}

bool NativeProcessDragonFly::HasThreadNoLock(lldb::tid_t thread_id) {
  for (const auto &thread : m_threads) {
    assert(thread && "thread list should not contain NULL threads");
    if (thread->GetID() == thread_id) {
      // We have this thread.
      return true;
    }
  }

  // We don't have this thread.
  return false;
}

NativeThreadDragonFly &NativeProcessDragonFly::AddThread(lldb::tid_t thread_id) {
  Log *log = GetLog(POSIXLog::Thread);
  LLDB_LOG(log, "pid {0} adding thread with tid {1}", GetID(), thread_id);

  assert(thread_id > 0);
  assert(!HasThreadNoLock(thread_id) &&
         "attempted to add a thread by id that already exists");

  // If this is the first thread, save it as the current thread
  if (m_threads.empty())
    SetCurrentThreadID(thread_id);

  m_threads.push_back(std::make_unique<NativeThreadDragonFly>(*this, thread_id));
  return static_cast<NativeThreadDragonFly &>(*m_threads.back());
}

void NativeProcessDragonFly::RemoveThread(lldb::tid_t thread_id) {
  Log *log = GetLog(POSIXLog::Thread);
  LLDB_LOG(log, "pid {0} removing thread with tid {1}", GetID(), thread_id);

  assert(thread_id > 0);
  assert(HasThreadNoLock(thread_id) &&
         "attempted to remove a thread that does not exist");

  for (auto it = m_threads.begin(); it != m_threads.end(); ++it) {
    if ((*it)->GetID() == thread_id) {
      m_threads.erase(it);
      break;
    }
  }

  if (GetCurrentThreadID() == thread_id)
    SetCurrentThreadID(m_threads.front()->GetID());
}

Status NativeProcessDragonFly::Attach() {
  // Attach to the requested process.
  // An attach will cause the thread to stop with a SIGSTOP.
  Status status = PtraceWrapper(PT_ATTACH, m_pid);
  if (status.Fail())
    return status;

  int wstatus;
  // Need to use WALLSIG otherwise we receive an error with errno=ECHLD At this
  // point we should have a thread stopped if waitpid succeeds.
  if ((wstatus = llvm::sys::RetryAfterSignal(-1, waitpid, m_pid, nullptr, 0)) <
      0)
    return Status(errno, eErrorTypePOSIX);

  // Initialize threads and tracing status
  // NB: this needs to be called before we set thread state
  status = SetupTrace();
  if (status.Fail())
    return status;

  for (const auto &thread : m_threads)
    static_cast<NativeThreadDragonFly &>(*thread).SetStoppedBySignal(SIGSTOP);

  // Let our process instance know the thread has stopped.
  SetCurrentThreadID(m_threads.front()->GetID());
  SetState(StateType::eStateStopped, false);
  return Status();
}

Status NativeProcessDragonFly::ReadMemory(lldb::addr_t addr, void *buf,
                                        size_t size, size_t &bytes_read) {
  unsigned char *dst = static_cast<unsigned char *>(buf);
  struct ptrace_io_desc io;

  Log *log = GetLog(POSIXLog::Memory);
  LLDB_LOG(log, "addr = {0}, buf = {1}, size = {2}", addr, buf, size);

  bytes_read = 0;
  io.piod_op = PIOD_READ_D;
  io.piod_len = size;

  do {
    io.piod_offs = (void *)(addr + bytes_read);
    io.piod_addr = dst + bytes_read;

    Status error = NativeProcessDragonFly::PtraceWrapper(PT_IO, GetID(), &io);
    if (error.Fail() || io.piod_len == 0)
      return error;

    bytes_read += io.piod_len;
    io.piod_len = size - bytes_read;
  } while (bytes_read < size);

  return Status();
}

Status NativeProcessDragonFly::WriteMemory(lldb::addr_t addr, const void *buf,
                                         size_t size, size_t &bytes_written) {
  const unsigned char *src = static_cast<const unsigned char *>(buf);
  Status error;
  struct ptrace_io_desc io;

  Log *log = GetLog(POSIXLog::Memory);
  LLDB_LOG(log, "addr = {0}, buf = {1}, size = {2}", addr, buf, size);

  bytes_written = 0;
  io.piod_op = PIOD_WRITE_D;
  io.piod_len = size;

  do {
    io.piod_addr =
        const_cast<void *>(static_cast<const void *>(src + bytes_written));
    io.piod_offs = (void *)(addr + bytes_written);

    Status error = NativeProcessDragonFly::PtraceWrapper(PT_IO, GetID(), &io);
    if (error.Fail() || io.piod_len == 0)
      return error;

    bytes_written += io.piod_len;
    io.piod_len = size - bytes_written;
  } while (bytes_written < size);

  return error;
}

llvm::ErrorOr<std::unique_ptr<llvm::MemoryBuffer>>
NativeProcessDragonFly::GetAuxvData() const {
  Log *log = GetLog(POSIXLog::Process);
  LLDB_LOG(log, "Tracing auxv data is not supported");
  return std::error_code(1, std::generic_category());
}

Status NativeProcessDragonFly::SetupTrace() {
  return Status("trace setup not implemented");
}

Status NativeProcessDragonFly::ReinitializeThreads() {
  return Status("reinitialize threads not implemented");
}

bool NativeProcessDragonFly::SupportHardwareSingleStepping() const {
  return true;
}

void NativeProcessDragonFly::MonitorClone(::pid_t child_pid, bool is_vfork,
                                        NativeThreadDragonFly &parent_thread) {
  Log *log = GetLog(POSIXLog::Process);
  LLDB_LOG(log, "fork, child_pid={0}", child_pid);

  int status;
  ::pid_t wait_pid =
      llvm::sys::RetryAfterSignal(-1, ::waitpid, child_pid, &status, 0);
  if (wait_pid != child_pid) {
    LLDB_LOG(log,
             "waiting for pid {0} failed. Assuming the pid has "
             "disappeared in the meantime",
             child_pid);
    return;
  }
  if (WIFEXITED(status)) {
    LLDB_LOG(log,
             "waiting for pid {0} returned an 'exited' event. Not "
             "tracking it.",
             child_pid);
    return;
  }

  LLDB_LOG(log, "MonitorClone unsupported");
  return;

}

llvm::Expected<std::string>
NativeProcessDragonFly::SaveCore(llvm::StringRef path_hint) {
  return llvm::createStringError(
      llvm::inconvertibleErrorCode(),
      "PT_COREDUMP not supported on DragonFly");
}
