--- hwy/base.h.orig	2023-08-29 18:54:45 UTC
+++ hwy/base.h
@@ -374,7 +374,7 @@ static constexpr HWY_MAYBE_UNUSED size_t
 // Required if HWY_HAVE_FLOAT16, i.e. RVV with zvfh or AVX3_SPR (with
 // sufficiently new compiler supporting avx512fp16). Do not use on clang-cl,
 // which is missing __extendhfsf2.
-#if ((HWY_ARCH_RVV && defined(__riscv_zvfh) && HWY_COMPILER_CLANG) || \
+#if (1 || (HWY_ARCH_RVV && defined(__riscv_zvfh) && HWY_COMPILER_CLANG) || \
      (HWY_ARCH_X86 && defined(__SSE2__) &&                            \
       ((HWY_COMPILER_CLANG >= 1600 && !HWY_COMPILER_CLANGCL) ||       \
        HWY_COMPILER_GCC_ACTUAL >= 1200)))
