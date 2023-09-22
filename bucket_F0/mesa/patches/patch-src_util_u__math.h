--- src/util/u_math.h.orig	2023-09-20 17:15:34 UTC
+++ src/util/u_math.h
@@ -59,6 +59,7 @@
 extern "C" {
 #endif
 
+#undef ALIGN
 
 #ifndef M_SQRT2
 #define M_SQRT2 1.41421356237309504880
