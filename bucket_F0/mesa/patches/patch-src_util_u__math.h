--- src/util/u_math.h.orig	2023-04-20 23:06:54 UTC
+++ src/util/u_math.h
@@ -54,6 +54,7 @@
 extern "C" {
 #endif
 
+#undef ALIGN
 
 #ifndef M_SQRT2
 #define M_SQRT2 1.41421356237309504880
