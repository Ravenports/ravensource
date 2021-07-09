--- modules/flann/include/opencv2/flann/defines.h.orig	2021-07-05 12:03:22 UTC
+++ modules/flann/include/opencv2/flann/defines.h
@@ -60,6 +60,9 @@
 #define FLANN_PLATFORM_32_BIT
 #endif
 
+#ifdef __sun__
+#undef CS
+#endif
 
 #undef FLANN_ARRAY_LEN
 #define FLANN_ARRAY_LEN(a) (sizeof(a)/sizeof(a[0]))
