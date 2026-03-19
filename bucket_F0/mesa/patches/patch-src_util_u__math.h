--- src/util/u_math.h.orig	2026-02-19 18:55:18 UTC
+++ src/util/u_math.h
@@ -60,6 +60,7 @@
 extern "C" {
 #endif
 
+#undef ALIGN
 
 #ifndef M_SQRT2
 #define M_SQRT2 1.41421356237309504880
