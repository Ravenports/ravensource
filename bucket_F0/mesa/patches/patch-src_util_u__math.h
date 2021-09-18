--- src/util/u_math.h.orig	2021-09-08 21:22:06 UTC
+++ src/util/u_math.h
@@ -51,6 +51,7 @@
 extern "C" {
 #endif
 
+#undef ALIGN
 
 #ifndef M_SQRT2
 #define M_SQRT2 1.41421356237309504880
