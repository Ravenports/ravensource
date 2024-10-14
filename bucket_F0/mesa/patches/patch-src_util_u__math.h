--- src/util/u_math.h.orig	2024-10-03 15:38:59 UTC
+++ src/util/u_math.h
@@ -60,6 +60,7 @@
 extern "C" {
 #endif
 
+#undef ALIGN
 
 #ifndef M_SQRT2
 #define M_SQRT2 1.41421356237309504880
