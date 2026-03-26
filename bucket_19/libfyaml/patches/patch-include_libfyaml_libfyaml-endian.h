--- include/libfyaml/libfyaml-endian.h.orig	2026-03-15 13:48:50 UTC
+++ include/libfyaml/libfyaml-endian.h
@@ -42,7 +42,7 @@
 extern "C" {
 #endif
 
-#if defined(__linux__) || defined(__CYGWIN__) || defined(__OpenBSD__) || defined(__GNU__) || defined(__EMSCRIPTEN__)
+#if defined(__linux__) || defined(__CYGWIN__) || defined(__OpenBSD__) || defined(__GNU__) || defined(__EMSCRIPTEN__) || defined(__sun__)
 # include <endian.h>
 #elif defined(__APPLE__)
 # include <libkern/OSByteOrder.h>
