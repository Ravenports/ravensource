--- src/util/u_math.h.orig	2024-04-24 18:00:13 UTC
+++ src/util/u_math.h
@@ -60,6 +60,7 @@
 extern "C" {
 #endif
 
+#undef ALIGN
 
 #ifndef M_SQRT2
 #define M_SQRT2 1.41421356237309504880
