//===-- source/Host/dragonfly/Host.cpp --------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include <sys/types.h>

#include <sys/exec.h>
#include <sys/ptrace.h>
#include <sys/sysctl.h>
#include <sys/user.h>

#include <machine/elf.h>

#include <cstdio>
#include <dlfcn.h>
#include <execinfo.h>

#include "lldb/Host/Host.h"
#include "lldb/Host/HostInfo.h"
#include "lldb/Utility/DataBufferHeap.h"
#include "lldb/Utility/DataExtractor.h"
#include "lldb/Utility/Endian.h"
#include "lldb/Utility/Log.h"
#include "lldb/Utility/NameMatches.h"
#include "lldb/Utility/ProcessInfo.h"
#include "lldb/Utility/Status.h"
#include "lldb/Utility/StreamString.h"

#include "llvm/TargetParser/Host.h"

extern "C" {
extern char **environ;
}

namespace lldb_private {
class ProcessLaunchInfo;
}

using namespace lldb;
using namespace lldb_private;

static bool
GetDragonFlyProcessArgs(const ProcessInstanceInfoMatch *match_info_ptr,
                      ProcessInstanceInfo &process_info) {
  if (!process_info.ProcessIDIsValid())
    return false;

  int pid = process_info.GetProcessID();

  int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_ARGS, pid};

  char arg_data[8192];
  size_t arg_data_size = sizeof(arg_data);
  if (::sysctl(mib, 4, arg_data, &arg_data_size, NULL, 0) != 0)
    return false;

  DataExtractor data(arg_data, arg_data_size, endian::InlHostByteOrder(),
                     sizeof(void *));
  lldb::offset_t offset = 0;
  const char *cstr;

  cstr = data.GetCStr(&offset);
  if (!cstr)
    return false;

  // Get pathname for pid. If that fails fall back to argv[0].
  char pathname[MAXPATHLEN];
  size_t pathname_len = sizeof(pathname);
  mib[2] = KERN_PROC_PATHNAME;
  if (::sysctl(mib, 4, pathname, &pathname_len, NULL, 0) == 0)
    process_info.GetExecutableFile().SetFile(pathname, FileSpec::Style::native);
  else
    process_info.GetExecutableFile().SetFile(cstr, FileSpec::Style::native);

  if (!(match_info_ptr == NULL ||
        NameMatches(process_info.GetExecutableFile().GetFilename().GetCString(),
                    match_info_ptr->GetNameMatchType(),
                    match_info_ptr->GetProcessInfo().GetName())))
    return false;

  process_info.SetArg0(cstr);
  Args &proc_args = process_info.GetArguments();
  while (1) {
    const uint8_t *p = data.PeekData(offset, 1);
    while ((p != NULL) && (*p == '\0') && offset < arg_data_size) {
      ++offset;
      p = data.PeekData(offset, 1);
    }
    if (p == NULL || offset >= arg_data_size)
      break;

    cstr = data.GetCStr(&offset);
    if (!cstr)
      break;

    proc_args.AppendArgument(llvm::StringRef(cstr));
  }

  return true;
}

static bool GetDragonFlyProcessCPUType(ProcessInstanceInfo &process_info) {
  if (process_info.ProcessIDIsValid()) {
    process_info.GetArchitecture() =
        HostInfo::GetArchitecture(HostInfo::eArchKindDefault);
    return true;
  }
  process_info.GetArchitecture().Clear();
  return false;
}

static bool GetDragonFlyProcessUserAndGroup(ProcessInstanceInfo &process_info) {
  struct kinfo_proc proc_kinfo;
  size_t proc_kinfo_size;
  const int pid = process_info.GetProcessID();
  int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, pid};

  if (!process_info.ProcessIDIsValid())
    goto error;

  proc_kinfo_size = sizeof(struct kinfo_proc);

  if (::sysctl(mib, 4, &proc_kinfo, &proc_kinfo_size, NULL, 0) != 0)
    goto error;

  if (proc_kinfo_size == 0)
    goto error;

  process_info.SetParentProcessID(proc_kinfo.kp_ppid);
  process_info.SetUserID(proc_kinfo.kp_ruid);
  process_info.SetGroupID(proc_kinfo.kp_rgid);
  process_info.SetEffectiveUserID(proc_kinfo.kp_uid);
  if (proc_kinfo.kp_ngroups > 0)
    process_info.SetEffectiveGroupID(proc_kinfo.kp_groups[0]);
  else
    process_info.SetEffectiveGroupID(UINT32_MAX);
  return true;

error:
  process_info.SetParentProcessID(LLDB_INVALID_PROCESS_ID);
  process_info.SetUserID(UINT32_MAX);
  process_info.SetGroupID(UINT32_MAX);
  process_info.SetEffectiveUserID(UINT32_MAX);
  process_info.SetEffectiveGroupID(UINT32_MAX);
  return false;
}

uint32_t Host::FindProcessesImpl(const ProcessInstanceInfoMatch &match_info,
                                 ProcessInstanceInfoList &process_infos) {
  const ::pid_t our_pid = ::getpid();
  const ::uid_t our_uid = ::getuid();
  std::vector<struct kinfo_proc> kinfos;
  // Special case, if lldb is being run as root we can attach to anything.
  bool all_users = match_info.GetMatchAllUsers() || (our_uid == 0);

  int mib[3] = {CTL_KERN, KERN_PROC, KERN_PROC_ALL};

  size_t pid_data_size = 0;
  if (::sysctl(mib, 3, NULL, &pid_data_size, NULL, 0) != 0)
    return 0;

  // Add a few extra in case a few more show up
  const size_t estimated_pid_count =
      (pid_data_size / sizeof(struct kinfo_proc)) + 10;

  kinfos.resize(estimated_pid_count);
  pid_data_size = kinfos.size() * sizeof(struct kinfo_proc);

  if (::sysctl(mib, 3, &kinfos[0], &pid_data_size, NULL, 0) != 0)
    return 0;

  const size_t actual_pid_count = (pid_data_size / sizeof(struct kinfo_proc));

  ProcessInstanceInfoMatch match_info_noname{match_info};
  match_info_noname.SetNameMatchType(NameMatch::Ignore);

  for (size_t i = 0; i < actual_pid_count; i++) {
    const struct kinfo_proc &kinfo = kinfos[i];

    /* Make sure the user is acceptable */
    if (!all_users && kinfo.kp_ruid != our_uid)
      continue;

    if (kinfo.kp_pid == our_pid ||   // Skip this process
        kinfo.kp_pid == 0 ||         // Skip kernel (kernel pid is 0)
        kinfo.kp_stat == SZOMB ||    // Zombies are bad
        kinfo.kp_flags & P_TRACED || // Being debugged?
        kinfo.kp_flags & P_WEXIT)    // Working on exiting
      continue;

    // Every thread is a process in DragonFly, but all the threads of a single
    // process have the same pid. Do not store the process info in the result
    // list if a process with given identifier is already registered there.
    bool already_registered = false;
    for (uint32_t pi = 0;
         !already_registered && (const int)kinfo.kp_nthreads > 1 &&
         pi < (const uint32_t)process_infos.size();
         pi++)
      already_registered =
          (process_infos[pi].GetProcessID() == (uint32_t)kinfo.kp_pid);

    if (already_registered)
      continue;

    ProcessInstanceInfo process_info;
    process_info.SetProcessID(kinfo.kp_pid);
    process_info.SetParentProcessID(kinfo.kp_ppid);
    process_info.SetUserID(kinfo.kp_ruid);
    process_info.SetGroupID(kinfo.kp_rgid);
    process_info.SetEffectiveUserID(kinfo.kp_svuid);
    process_info.SetEffectiveGroupID(kinfo.kp_svgid);

    // Make sure our info matches before we go fetch the name and cpu type
    if (match_info_noname.Matches(process_info) &&
        GetDragonFlyProcessArgs(&match_info, process_info)) {
      GetDragonFlyProcessCPUType(process_info);
      if (match_info.Matches(process_info))
        process_infos.push_back(process_info);
    }
  }

  return process_infos.size();
}

bool Host::GetProcessInfo(lldb::pid_t pid, ProcessInstanceInfo &process_info) {
  process_info.SetProcessID(pid);

  if (GetDragonFlyProcessArgs(NULL, process_info)) {
    // should use libprocstat instead of going right into sysctl?
    GetDragonFlyProcessCPUType(process_info);
    GetDragonFlyProcessUserAndGroup(process_info);
    return true;
  }

  process_info.Clear();
  return false;
}

Environment Host::GetEnvironment() { return Environment(environ); }

Status Host::ShellExpandArguments(ProcessLaunchInfo &launch_info) {
  return Status("unimplemented");
}
