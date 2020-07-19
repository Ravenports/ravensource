--- modules/flann/include/opencv2/flann/defines.h.orig	2020-07-17 22:43:40 UTC
+++ modules/flann/include/opencv2/flann/defines.h
@@ -60,6 +60,9 @@
 #define FLANN_PLATFORM_32_BIT
 #endif
 
+#ifdef __sun__
+#undef CS
+#endif
 
 #undef FLANN_ARRAY_LEN
 #define FLANN_ARRAY_LEN(a) (sizeof(a)/sizeof(a[0]))
