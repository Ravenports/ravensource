//===-- NativeRegisterContextDragonFly.cpp ----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "NativeRegisterContextDragonFly.h"

#include "Plugins/Process/DragonFly/NativeProcessDragonFly.h"

#include "lldb/Host/common/NativeProcessProtocol.h"

using namespace lldb_private;
using namespace lldb_private::process_dragonfly;

// clang-format off
#include <sys/types.h>
#include <sys/ptrace.h>
// clang-format on

NativeProcessDragonFly &NativeRegisterContextDragonFly::GetProcess() {
  return static_cast<NativeProcessDragonFly &>(m_thread.GetProcess());
}

::pid_t NativeRegisterContextDragonFly::GetProcessPid() {
  return GetProcess().GetID();
}
