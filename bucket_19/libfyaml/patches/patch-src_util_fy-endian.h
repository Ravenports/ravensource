--- src/util/fy-endian.h.orig	2026-02-03 18:22:18 UTC
+++ src/util/fy-endian.h
@@ -8,7 +8,7 @@
 #ifndef FY_ENDIAN_H
 #define FY_ENDIAN_H
 
-#if defined(__linux__) || defined(__CYGWIN__) || defined(__OpenBSD__) || defined(__GNU__) || defined(__EMSCRIPTEN__)
+#if defined(__linux__) || defined(__CYGWIN__) || defined(__OpenBSD__) || defined(__GNU__) || defined(__EMSCRIPTEN__) || defined(__sun__)
 # include <endian.h>
 #elif defined(__APPLE__)
 # include <libkern/OSByteOrder.h>
