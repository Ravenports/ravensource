--- extensions/sse2-float.c.orig	2026-03-10 15:56:45 UTC
+++ extensions/sse2-float.c
@@ -397,7 +397,7 @@ static void conv_rgbaF_linear_rgbAF_gamm
                                            float       *dst, 
                                            long         samples)
 {
-  float *tmp = alloca (sizeof(float)*4*samples);
+  float *tmp = __builtin_alloca (sizeof(float)*4*samples);
   conv_rgbaF_linear_rgbaF_gamma (conversion, src, tmp, samples);
   conv_rgbaF_linear_rgbAF_linear (conversion, tmp, dst, samples);
 }
