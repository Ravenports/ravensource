//===-- NativeRegisterContextDragonFly.h --------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef lldb_NativeRegisterContextDragonFly_h
#define lldb_NativeRegisterContextDragonFly_h

#include "Plugins/Process/Utility/NativeRegisterContextRegisterInfo.h"

namespace lldb_private {
namespace process_dragonfly {

class NativeProcessDragonFly;
class NativeThreadDragonFly;

class NativeRegisterContextDragonFly
    : public virtual NativeRegisterContextRegisterInfo {
public:
  // This function is implemented in the NativeRegisterContextDragonFly_*
  // subclasses to create a new instance of the host specific
  // NativeRegisterContextDragonFly. The implementations can't collide as only one
  // NativeRegisterContextDragonFly_* variant should be compiled into the final
  // executable.
  static NativeRegisterContextDragonFly *
  CreateHostNativeRegisterContextDragonFly(const ArchSpec &target_arch,
                                         NativeThreadDragonFly &native_thread);
  virtual llvm::Error
  CopyHardwareWatchpointsFrom(NativeRegisterContextDragonFly &source) = 0;

protected:
  virtual NativeProcessDragonFly &GetProcess();
  virtual ::pid_t GetProcessPid();
};

} // namespace process_dragonfly
} // namespace lldb_private

#endif // #ifndef lldb_NativeRegisterContextDragonFly_h
