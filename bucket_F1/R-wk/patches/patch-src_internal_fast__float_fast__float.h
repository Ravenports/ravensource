--- src/internal/fast_float/fast_float.h.orig	2021-12-21 00:36:19 UTC
+++ src/internal/fast_float/fast_float.h
@@ -166,7 +166,7 @@ from_chars_result from_chars_advanced(co
 #ifdef _WIN32
 #define FASTFLOAT_IS_BIG_ENDIAN 0
 #else
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <machine/endian.h>
 #elif defined(sun) || defined(__sun)
 #include <sys/byteorder.h>
