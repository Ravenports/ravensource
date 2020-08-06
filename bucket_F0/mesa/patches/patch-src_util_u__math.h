--- src/util/u_math.h.orig	2020-08-05 20:35:08 UTC
+++ src/util/u_math.h
@@ -51,6 +51,7 @@
 extern "C" {
 #endif
 
+#undef ALIGN
 
 #ifndef M_SQRT2
 #define M_SQRT2 1.41421356237309504880
