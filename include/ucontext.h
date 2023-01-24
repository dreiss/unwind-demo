#pragma once

#include <assert.h>
#include <stdint.h>

#ifdef __riscv

#if __riscv_flen == 64
#define UCONTEXT_FPREG double
#elif __riscv_flen == 32
#define UCONTEXT_FPREG float
#elif defined(__riscv_float_abi_soft)
#define UCONTEXT_FPREG unused
#else
#error "Unsupported RISC-V floating-point size"
#endif

typedef struct {
  int honk; // XXX
  struct {
    uintptr_t regs[32];
#if !defined(__riscv_float_abi_soft)
    UCONTEXT_FPREG fpregs[32];
    uint32_t fcsf;
#endif
  } uc_mcontext;
} ucontext_t;

#undef UCONTEXT_FPREG

// We need the build system to define this so libunwind can use it in assembly.
// Verify the value, but only if defined.
#ifdef UC_MCONTEXT_REGS_OFF
static_assert(UC_MCONTEXT_REGS_OFF == offsetof(ucontext_t, uc_mcontext));
#endif

#else
#error "Unsupported architecture"
#endif
