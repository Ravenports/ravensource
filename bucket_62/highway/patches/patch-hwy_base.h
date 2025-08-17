--- hwy/base.h.orig	2025-08-14 07:25:53 UTC
+++ hwy/base.h
@@ -1205,7 +1205,7 @@ HWY_API HWY_BITCASTSCALAR_CONSTEXPR To B
 // Compiler supports _Float16, not necessarily with operators.
 #if HWY_NEON_HAVE_F16C || HWY_RVV_HAVE_F16_VEC || HWY_SSE2_HAVE_F16_TYPE || \
     __SPIRV_DEVICE__
-#define HWY_HAVE_SCALAR_F16_TYPE 1
+#define HWY_HAVE_SCALAR_F16_TYPE 0
 #else
 #define HWY_HAVE_SCALAR_F16_TYPE 0
 #endif
@@ -1730,7 +1730,7 @@ HWY_F16_CONSTEXPR inline std::partial_or
 
 // Compiler supports __bf16, not necessarily with operators.
 #if HWY_ARM_HAVE_SCALAR_BF16_TYPE || HWY_SSE2_HAVE_SCALAR_BF16_TYPE
-#define HWY_HAVE_SCALAR_BF16_TYPE 1
+#define HWY_HAVE_SCALAR_BF16_TYPE 0
 #else
 #define HWY_HAVE_SCALAR_BF16_TYPE 0
 #endif
