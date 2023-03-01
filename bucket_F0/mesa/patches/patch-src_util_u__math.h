--- src/util/u_math.h.orig	2023-02-22 20:35:56 UTC
+++ src/util/u_math.h
@@ -52,6 +52,7 @@
 extern "C" {
 #endif
 
+#undef ALIGN
 
 #ifndef M_SQRT2
 #define M_SQRT2 1.41421356237309504880
