On Illumos int8_t != ET, so be explicit about the cast to be used here.

--- modules/imgproc/src/resize.cpp.orig	2025-12-30 07:52:05 UTC
+++ modules/imgproc/src/resize.cpp
@@ -709,7 +709,7 @@ template <typename ET, typename FT>
 void vlineSet(FT* src, ET* dst, int dst_width)
 {
     for (int i = 0; i < dst_width; i++)
-        dst[i] = src[i];
+        dst[i] = int8_t(src[i]);
 }
 template <>
 void vlineSet<uint8_t, ufixedpoint16>(ufixedpoint16* src, uint8_t* dst, int dst_width)
@@ -741,7 +741,7 @@ void vlineResize(FT* src, size_t src_ste
         typename FT::WT res = src[i] * m[0];
         for (int k = 1; k < n; k++)
             res = res + src[i + k*src_step] * m[k];
-        dst[i] = res;
+        dst[i] = int8_t(res);
     }
 }
 template <>
