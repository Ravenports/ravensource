--- hwy/base.h.orig	2026-04-22 16:17:25 UTC
+++ hwy/base.h
@@ -1184,7 +1184,7 @@ HWY_API HWY_BITCASTSCALAR_CONSTEXPR To B
 // Compiler supports _Float16, not necessarily with operators.
 #if HWY_NEON_HAVE_F16C || HWY_RVV_HAVE_F16_VEC || HWY_SSE2_HAVE_F16_TYPE || \
     __SPIRV_DEVICE__
-#define HWY_HAVE_SCALAR_F16_TYPE 1
+#define HWY_HAVE_SCALAR_F16_TYPE 0
 #else
 #define HWY_HAVE_SCALAR_F16_TYPE 0
 #endif
@@ -1695,7 +1695,7 @@ HWY_F16_CONSTEXPR inline std::partial_or
 
 // Compiler supports __bf16, not necessarily with operators.
 #if HWY_ARM_HAVE_SCALAR_BF16_TYPE || HWY_SSE2_HAVE_SCALAR_BF16_TYPE
-#define HWY_HAVE_SCALAR_BF16_TYPE 1
+#define HWY_HAVE_SCALAR_BF16_TYPE 0
 #else
 #define HWY_HAVE_SCALAR_BF16_TYPE 0
 #endif
