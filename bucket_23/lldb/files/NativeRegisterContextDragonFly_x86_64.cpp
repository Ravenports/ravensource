//===-- NativeRegisterContextDragonFly_x86_64.cpp ---------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#if defined(__x86_64__)

#include "NativeRegisterContextDragonFly_x86_64.h"

// clang-format off
#include <machine/npx.h>
// clang-format on

#include "lldb/Host/HostInfo.h"
#include "lldb/Utility/DataBufferHeap.h"
#include "lldb/Utility/Log.h"
#include "lldb/Utility/RegisterValue.h"
#include "lldb/Utility/Status.h"

#include "NativeProcessDragonFly.h"
#include "Plugins/Process/Utility/RegisterContextFreeBSD_x86_64.h"
#include <optional>

using namespace lldb_private;
using namespace lldb_private::process_dragonfly;

// x86 64-bit general purpose registers.
static const uint32_t g_gpr_regnums_x86_64[] = {
    lldb_rax_x86_64,    lldb_rbx_x86_64,    lldb_rcx_x86_64, lldb_rdx_x86_64,
    lldb_rdi_x86_64,    lldb_rsi_x86_64,    lldb_rbp_x86_64, lldb_rsp_x86_64,
    lldb_r8_x86_64,     lldb_r9_x86_64,     lldb_r10_x86_64, lldb_r11_x86_64,
    lldb_r12_x86_64,    lldb_r13_x86_64,    lldb_r14_x86_64, lldb_r15_x86_64,
    lldb_rip_x86_64,    lldb_rflags_x86_64, lldb_cs_x86_64,  lldb_fs_x86_64,
    lldb_gs_x86_64,     lldb_ss_x86_64,     lldb_ds_x86_64,  lldb_es_x86_64,
    lldb_eax_x86_64,    lldb_ebx_x86_64,    lldb_ecx_x86_64, lldb_edx_x86_64,
    lldb_edi_x86_64,    lldb_esi_x86_64,    lldb_ebp_x86_64, lldb_esp_x86_64,
    lldb_r8d_x86_64,  // Low 32 bits or r8
    lldb_r9d_x86_64,  // Low 32 bits or r9
    lldb_r10d_x86_64, // Low 32 bits or r10
    lldb_r11d_x86_64, // Low 32 bits or r11
    lldb_r12d_x86_64, // Low 32 bits or r12
    lldb_r13d_x86_64, // Low 32 bits or r13
    lldb_r14d_x86_64, // Low 32 bits or r14
    lldb_r15d_x86_64, // Low 32 bits or r15
    lldb_ax_x86_64,     lldb_bx_x86_64,     lldb_cx_x86_64,  lldb_dx_x86_64,
    lldb_di_x86_64,     lldb_si_x86_64,     lldb_bp_x86_64,  lldb_sp_x86_64,
    lldb_r8w_x86_64,  // Low 16 bits or r8
    lldb_r9w_x86_64,  // Low 16 bits or r9
    lldb_r10w_x86_64, // Low 16 bits or r10
    lldb_r11w_x86_64, // Low 16 bits or r11
    lldb_r12w_x86_64, // Low 16 bits or r12
    lldb_r13w_x86_64, // Low 16 bits or r13
    lldb_r14w_x86_64, // Low 16 bits or r14
    lldb_r15w_x86_64, // Low 16 bits or r15
    lldb_ah_x86_64,     lldb_bh_x86_64,     lldb_ch_x86_64,  lldb_dh_x86_64,
    lldb_al_x86_64,     lldb_bl_x86_64,     lldb_cl_x86_64,  lldb_dl_x86_64,
    lldb_dil_x86_64,    lldb_sil_x86_64,    lldb_bpl_x86_64, lldb_spl_x86_64,
    lldb_r8l_x86_64,    // Low 8 bits or r8
    lldb_r9l_x86_64,    // Low 8 bits or r9
    lldb_r10l_x86_64,   // Low 8 bits or r10
    lldb_r11l_x86_64,   // Low 8 bits or r11
    lldb_r12l_x86_64,   // Low 8 bits or r12
    lldb_r13l_x86_64,   // Low 8 bits or r13
    lldb_r14l_x86_64,   // Low 8 bits or r14
    lldb_r15l_x86_64,   // Low 8 bits or r15
    LLDB_INVALID_REGNUM // register sets need to end with this flag
};
static_assert((sizeof(g_gpr_regnums_x86_64) / sizeof(g_gpr_regnums_x86_64[0])) -
                      1 ==
                  k_num_gpr_registers_x86_64,
              "g_gpr_regnums_x86_64 has wrong number of register infos");

// x86 64-bit floating point registers.
static const uint32_t g_fpu_regnums_x86_64[] = {
    lldb_fctrl_x86_64,  lldb_fstat_x86_64, lldb_ftag_x86_64,
    lldb_fop_x86_64,    lldb_fiseg_x86_64, lldb_fioff_x86_64,
    lldb_fip_x86_64,    lldb_foseg_x86_64, lldb_fooff_x86_64,
    lldb_fdp_x86_64,    lldb_mxcsr_x86_64, lldb_mxcsrmask_x86_64,
    lldb_st0_x86_64,    lldb_st1_x86_64,   lldb_st2_x86_64,
    lldb_st3_x86_64,    lldb_st4_x86_64,   lldb_st5_x86_64,
    lldb_st6_x86_64,    lldb_st7_x86_64,   lldb_mm0_x86_64,
    lldb_mm1_x86_64,    lldb_mm2_x86_64,   lldb_mm3_x86_64,
    lldb_mm4_x86_64,    lldb_mm5_x86_64,   lldb_mm6_x86_64,
    lldb_mm7_x86_64,    lldb_xmm0_x86_64,  lldb_xmm1_x86_64,
    lldb_xmm2_x86_64,   lldb_xmm3_x86_64,  lldb_xmm4_x86_64,
    lldb_xmm5_x86_64,   lldb_xmm6_x86_64,  lldb_xmm7_x86_64,
    lldb_xmm8_x86_64,   lldb_xmm9_x86_64,  lldb_xmm10_x86_64,
    lldb_xmm11_x86_64,  lldb_xmm12_x86_64, lldb_xmm13_x86_64,
    lldb_xmm14_x86_64,  lldb_xmm15_x86_64,
    LLDB_INVALID_REGNUM // register sets need to end with this flag
};
static_assert((sizeof(g_fpu_regnums_x86_64) / sizeof(g_fpu_regnums_x86_64[0])) -
                      1 ==
                  k_num_fpr_registers_x86_64,
              "g_fpu_regnums_x86_64 has wrong number of register infos");

static const uint32_t g_avx_regnums_x86_64[] = {
    lldb_ymm0_x86_64,   lldb_ymm1_x86_64,  lldb_ymm2_x86_64,  lldb_ymm3_x86_64,
    lldb_ymm4_x86_64,   lldb_ymm5_x86_64,  lldb_ymm6_x86_64,  lldb_ymm7_x86_64,
    lldb_ymm8_x86_64,   lldb_ymm9_x86_64,  lldb_ymm10_x86_64, lldb_ymm11_x86_64,
    lldb_ymm12_x86_64,  lldb_ymm13_x86_64, lldb_ymm14_x86_64, lldb_ymm15_x86_64,
    LLDB_INVALID_REGNUM // register sets need to end with this flag
};
static_assert((sizeof(g_avx_regnums_x86_64) / sizeof(g_avx_regnums_x86_64[0])) -
                      1 ==
                  k_num_avx_registers_x86_64,
              "g_avx_regnums_x86_64 has wrong number of register infos");

static const uint32_t g_mpx_regnums_x86_64[] = {
    // Note: we currently do not provide them but this is needed to avoid
    // unnamed groups in SBFrame::GetRegisterContext().
    lldb_bnd0_x86_64,   lldb_bnd1_x86_64,    lldb_bnd2_x86_64,
    lldb_bnd3_x86_64,   lldb_bndcfgu_x86_64, lldb_bndstatus_x86_64,
    LLDB_INVALID_REGNUM // register sets need to end with this flag
};
static_assert((sizeof(g_mpx_regnums_x86_64) / sizeof(g_mpx_regnums_x86_64[0])) -
                      1 ==
                  k_num_mpx_registers_x86_64,
              "g_mpx_regnums_x86_64 has wrong number of register infos");

// x86 debug registers.
static const uint32_t g_dbr_regnums_x86_64[] = {
    lldb_dr0_x86_64,    lldb_dr1_x86_64, lldb_dr2_x86_64, lldb_dr3_x86_64,
    lldb_dr4_x86_64,    lldb_dr5_x86_64, lldb_dr6_x86_64, lldb_dr7_x86_64,
    LLDB_INVALID_REGNUM // register sets need to end with this flag
};
static_assert((sizeof(g_dbr_regnums_x86_64) / sizeof(g_dbr_regnums_x86_64[0])) -
                      1 ==
                  k_num_dbr_registers_x86_64,
              "g_dbr_regnums_x86_64 has wrong number of register infos");


// Number of register sets provided by this context.
enum { k_num_register_sets = 5 };

// Register sets for x86 64-bit.
static const RegisterSet g_reg_sets_x86_64[k_num_register_sets] = {
    {"General Purpose Registers", "gpr", k_num_gpr_registers_x86_64,
     g_gpr_regnums_x86_64},
    {"Floating Point Registers", "fpu", k_num_fpr_registers_x86_64,
     g_fpu_regnums_x86_64},
    {"Debug Registers", "dbr", k_num_dbr_registers_x86_64,
     g_dbr_regnums_x86_64},
    {"Advanced Vector Extensions", "avx", k_num_avx_registers_x86_64,
     g_avx_regnums_x86_64},
    {"Memory Protection Extensions", "mpx", k_num_mpx_registers_x86_64,
     g_mpx_regnums_x86_64},
};

#define REG_CONTEXT_SIZE (GetRegisterInfoInterface().GetGPRSize())

NativeRegisterContextDragonFly *
NativeRegisterContextDragonFly::CreateHostNativeRegisterContextDragonFly(
    const ArchSpec &target_arch, NativeThreadDragonFly &native_thread) {
  return new NativeRegisterContextDragonFly_x86_64(target_arch, native_thread);
}

// NativeRegisterContextDragonFly_x86_64 members.

static RegisterInfoInterface *
CreateRegisterInfoInterface(const ArchSpec &target_arch) {
    assert((HostInfo::GetArchitecture().GetAddressByteSize() == 8) &&
           "Register setting path assumes this is a 64-bit host");
    // X86_64 hosts know how to work with 64-bit and 32-bit EXEs using the
    // x86_64 register context.
    return new RegisterContextFreeBSD_x86_64(target_arch);
}

NativeRegisterContextDragonFly_x86_64::NativeRegisterContextDragonFly_x86_64(
    const ArchSpec &target_arch, NativeThreadDragonFly &native_thread)
    : NativeRegisterContextRegisterInfo(
          native_thread, CreateRegisterInfoInterface(target_arch)),
      NativeRegisterContextDBReg_x86(native_thread), m_regset_offsets({0}) {
  assert(m_gpr.size() == GetRegisterInfoInterface().GetGPRSize());
  std::array<uint32_t, MaxRegSet + 1> first_regnos;

  first_regnos[FPRegSet] = lldb_fctrl_x86_64;
  first_regnos[DBRegSet] = lldb_dr0_x86_64;

  for (int i : {FPRegSet, DBRegSet})
    m_regset_offsets[i] = GetRegisterInfoInterface()
                              .GetRegisterInfo()[first_regnos[i]]
                              .byte_offset;
}

uint32_t NativeRegisterContextDragonFly_x86_64::GetRegisterSetCount() const {
  return k_num_register_sets;
}

const RegisterSet *
NativeRegisterContextDragonFly_x86_64::GetRegisterSet(uint32_t set_index) const {
  return &g_reg_sets_x86_64[set_index];
}

std::optional<NativeRegisterContextDragonFly_x86_64::RegSetKind>
NativeRegisterContextDragonFly_x86_64::GetSetForNativeRegNum(uint32_t reg_num) const {
  if (reg_num >= k_first_gpr_x86_64 && reg_num <= k_last_gpr_x86_64)
      return GPRegSet;
  if (reg_num >= k_first_fpr_x86_64 && reg_num <= k_last_fpr_x86_64)
      return FPRegSet;
  if (reg_num >= k_first_avx_x86_64 && reg_num <= k_last_avx_x86_64)
      return YMMRegSet;
  if (reg_num >= k_first_mpxr_x86_64 && reg_num <= k_last_mpxr_x86_64)
      return std::nullopt; // MPXR
  if (reg_num >= k_first_mpxc_x86_64 && reg_num <= k_last_mpxc_x86_64)
      return std::nullopt; // MPXC
  if (reg_num >= k_first_dbr_x86_64 && reg_num <= k_last_dbr_x86_64)
      return DBRegSet; // DBR

  llvm_unreachable("Register does not belong to any register set");
}

Status NativeRegisterContextDragonFly_x86_64::ReadRegisterSet(RegSetKind set) {
  switch (set) {
  case GPRegSet:
    return NativeProcessDragonFly::PtraceWrapper(PT_GETREGS, m_thread.GetID(),
                                               m_gpr.data());
  case FPRegSet:
    return NativeProcessDragonFly::PtraceWrapper(PT_GETFPREGS, m_thread.GetID(),
                                               m_fpr.data());
  case DBRegSet:
    return NativeProcessDragonFly::PtraceWrapper(PT_GETDBREGS, m_thread.GetID(),
                                               m_dbr.data());
  case YMMRegSet:
  case MPXRegSet: {
       Status error;
       error.SetErrorString("YMM/MPX registers not supported");
       return error;
    }
  }
  llvm_unreachable("NativeRegisterContextDragonFly_x86_64::ReadRegisterSet");
}

Status NativeRegisterContextDragonFly_x86_64::WriteRegisterSet(RegSetKind set) {
  switch (set) {
  case GPRegSet:
    return NativeProcessDragonFly::PtraceWrapper(PT_SETREGS, m_thread.GetID(),
                                               m_gpr.data());
  case FPRegSet:
    return NativeProcessDragonFly::PtraceWrapper(PT_SETFPREGS, m_thread.GetID(),
                                               m_fpr.data());
  case DBRegSet:
    return NativeProcessDragonFly::PtraceWrapper(PT_SETDBREGS, m_thread.GetID(),
                                               m_dbr.data());
  case YMMRegSet:
  case MPXRegSet: {
    // ReadRegisterSet() must always be called before WriteRegisterSet().
       Status error;
       error.SetErrorString("YMM/MPX registers not supported");
       return error;
    }
  }
  llvm_unreachable("NativeRegisterContextDragonFly_x86_64::WriteRegisterSet");
}

Status
NativeRegisterContextDragonFly_x86_64::ReadRegister(const RegisterInfo *reg_info,
                                                  RegisterValue &reg_value) {
  Status error;

  if (!reg_info) {
    error.SetErrorString("reg_info NULL");
    return error;
  }

  uint32_t reg = reg_info->kinds[lldb::eRegisterKindLLDB];
  if (reg == LLDB_INVALID_REGNUM) {
    // This is likely an internal register for lldb use only and should not be
    // directly queried.
    error.SetErrorStringWithFormat("register \"%s\" is an internal-only lldb "
                                   "register, cannot read directly",
                                   reg_info->name);
    return error;
  }

  std::optional<RegSetKind> opt_set = GetSetForNativeRegNum(reg);
  if (!opt_set) {
    // This is likely an internal register for lldb use only and should not be
    // directly queried.
    error.SetErrorStringWithFormat("register \"%s\" is in unrecognized set",
                                   reg_info->name);
    return error;
  }

  RegSetKind set = opt_set.value();
  error = ReadRegisterSet(set);
  if (error.Fail())
    return error;

  switch (set) {
  case GPRegSet:
  case FPRegSet:
  case DBRegSet: {
    void *data = GetOffsetRegSetData(set, reg_info->byte_offset);
    FXSAVE *fpr = reinterpret_cast<FXSAVE *>(m_fpr.data());
    if (data == &fpr->ftag) // ftag
      reg_value.SetUInt16(
          AbridgedToFullTagWord(fpr->ftag, fpr->fstat, fpr->stmm));
    else
      reg_value.SetBytes(data, reg_info->byte_size, endian::InlHostByteOrder());
    break;
  }
  case YMMRegSet: {
    std::optional<YMMSplitPtr> ymm_reg = GetYMMSplitReg(reg);
    if (!ymm_reg) {
      error.SetErrorStringWithFormat(
          "register \"%s\" not supported by CPU/kernel", reg_info->name);
    } else {
      YMMReg ymm = XStateToYMM(ymm_reg->xmm, ymm_reg->ymm_hi);
      reg_value.SetBytes(ymm.bytes, reg_info->byte_size,
                         endian::InlHostByteOrder());
    }
    break;
  }
  case MPXRegSet:
    llvm_unreachable("MPX regset should have returned error");
  }

  return error;
}

Status NativeRegisterContextDragonFly_x86_64::WriteRegister(
    const RegisterInfo *reg_info, const RegisterValue &reg_value) {

  Status error;

  if (!reg_info) {
    error.SetErrorString("reg_info NULL");
    return error;
  }

  uint32_t reg = reg_info->kinds[lldb::eRegisterKindLLDB];
  if (reg == LLDB_INVALID_REGNUM) {
    // This is likely an internal register for lldb use only and should not be
    // directly queried.
    error.SetErrorStringWithFormat("register \"%s\" is an internal-only lldb "
                                   "register, cannot read directly",
                                   reg_info->name);
    return error;
  }

  std::optional<RegSetKind> opt_set = GetSetForNativeRegNum(reg);
  if (!opt_set) {
    // This is likely an internal register for lldb use only and should not be
    // directly queried.
    error.SetErrorStringWithFormat("register \"%s\" is in unrecognized set",
                                   reg_info->name);
    return error;
  }

  RegSetKind set = opt_set.value();
  error = ReadRegisterSet(set);
  if (error.Fail())
    return error;

  switch (set) {
  case GPRegSet:
  case FPRegSet:
  case DBRegSet: {
    void *data = GetOffsetRegSetData(set, reg_info->byte_offset);
    FXSAVE *fpr = reinterpret_cast<FXSAVE *>(m_fpr.data());
    if (data == &fpr->ftag) // ftag
      fpr->ftag = FullToAbridgedTagWord(reg_value.GetAsUInt16());
    else
      ::memcpy(data, reg_value.GetBytes(), reg_value.GetByteSize());
    break;
  }
  case YMMRegSet: {
    std::optional<YMMSplitPtr> ymm_reg = GetYMMSplitReg(reg);
    if (!ymm_reg) {
      error.SetErrorStringWithFormat(
          "register \"%s\" not supported by CPU/kernel", reg_info->name);
    } else {
      YMMReg ymm;
      ::memcpy(ymm.bytes, reg_value.GetBytes(), reg_value.GetByteSize());
      YMMToXState(ymm, ymm_reg->xmm, ymm_reg->ymm_hi);
    }
    break;
  }
  case MPXRegSet:
    llvm_unreachable("MPX regset should have returned error");
  }

  return WriteRegisterSet(set);
}

Status NativeRegisterContextDragonFly_x86_64::ReadAllRegisterValues(
    lldb::WritableDataBufferSP &data_sp) {
  Status error;

  data_sp.reset(new DataBufferHeap(REG_CONTEXT_SIZE, 0));
  error = ReadRegisterSet(GPRegSet);
  if (error.Fail())
    return error;

  uint8_t *dst = data_sp->GetBytes();
  ::memcpy(dst, m_gpr.data(), GetRegisterInfoInterface().GetGPRSize());
  dst += GetRegisterInfoInterface().GetGPRSize();

  return error;
}

Status NativeRegisterContextDragonFly_x86_64::WriteAllRegisterValues(
    const lldb::DataBufferSP &data_sp) {
  Status error;

  if (!data_sp) {
    error.SetErrorStringWithFormat(
        "NativeRegisterContextDragonFly_x86_64::%s invalid data_sp provided",
        __FUNCTION__);
    return error;
  }

  if (data_sp->GetByteSize() != REG_CONTEXT_SIZE) {
    error.SetErrorStringWithFormat(
        "NativeRegisterContextDragonFly_x86_64::%s data_sp contained mismatched "
        "data size, expected %zu, actual %" PRIu64,
        __FUNCTION__, REG_CONTEXT_SIZE, data_sp->GetByteSize());
    return error;
  }

  const uint8_t *src = data_sp->GetBytes();
  if (src == nullptr) {
    error.SetErrorStringWithFormat("NativeRegisterContextDragonFly_x86_64::%s "
                                   "DataBuffer::GetBytes() returned a null "
                                   "pointer",
                                   __FUNCTION__);
    return error;
  }
  ::memcpy(m_gpr.data(), src, GetRegisterInfoInterface().GetGPRSize());

  error = WriteRegisterSet(GPRegSet);
  if (error.Fail())
    return error;
  src += GetRegisterInfoInterface().GetGPRSize();

  return error;
}

llvm::Error NativeRegisterContextDragonFly_x86_64::CopyHardwareWatchpointsFrom(
    NativeRegisterContextDragonFly &source) {
  auto &r_source = static_cast<NativeRegisterContextDragonFly_x86_64 &>(source);
  // NB: This implicitly reads the whole dbreg set.
  RegisterValue dr7;
  Status res = r_source.ReadRegister(GetDR(7), dr7);
  if (!res.Fail()) {
    // copy dbregs only if any watchpoints were set
    if ((dr7.GetAsUInt64() & 0xFF) == 0)
      return llvm::Error::success();

    m_dbr = r_source.m_dbr;
    res = WriteRegisterSet(DBRegSet);
  }
  return res.ToError();
}

uint8_t *
NativeRegisterContextDragonFly_x86_64::GetOffsetRegSetData(RegSetKind set,
                                                         size_t reg_offset) {
  uint8_t *base;
  base = 0;
  switch (set) {
  case GPRegSet:
    base = m_gpr.data();
    break;
  case FPRegSet:
    base = m_fpr.data();
    break;
  case DBRegSet:
    base = m_dbr.data();
    break;
  case YMMRegSet:
    llvm_unreachable("GetRegSetData() is unsuitable for this regset.");
  case MPXRegSet:
    llvm_unreachable("MPX regset should have returned error");
  }
  assert(reg_offset >= m_regset_offsets[set]);
  return base + (reg_offset - m_regset_offsets[set]);
}

std::optional<NativeRegisterContextDragonFly_x86_64::YMMSplitPtr>
NativeRegisterContextDragonFly_x86_64::GetYMMSplitReg(uint32_t reg) {
  uint32_t offset = m_xsave_offsets[YMMRegSet];
  if (offset == LLDB_INVALID_XSAVE_OFFSET)
    return std::nullopt;

  uint32_t reg_index;
  reg_index = reg - lldb_ymm0_x86_64;

  auto *fpreg = reinterpret_cast<struct savexmm64 *>(m_xsave.data());
  auto *ymmreg = reinterpret_cast<struct ymmacc *>(m_xsave.data() + offset);

  return YMMSplitPtr{&fpreg->sv_xmm[reg_index], &ymmreg[reg_index]};
}

#endif // defined(__x86_64__)
