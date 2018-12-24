--- modules/flann/include/opencv2/flann/defines.h.orig	2018-12-21 14:31:20 UTC
+++ modules/flann/include/opencv2/flann/defines.h
@@ -58,6 +58,9 @@
 #define FLANN_PLATFORM_32_BIT
 #endif
 
+#ifdef __sun__
+#undef CS
+#endif
 
 #undef FLANN_ARRAY_LEN
 #define FLANN_ARRAY_LEN(a) (sizeof(a)/sizeof(a[0]))
