--- src/util/u_math.h.orig	2025-01-22 18:12:23 UTC
+++ src/util/u_math.h
@@ -60,6 +60,7 @@
 extern "C" {
 #endif
 
+#undef ALIGN
 
 #ifndef M_SQRT2
 #define M_SQRT2 1.41421356237309504880
