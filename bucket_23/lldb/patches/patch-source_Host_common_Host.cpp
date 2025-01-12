--- source/Host/common/Host.cpp.orig	2024-12-17 11:04:04 UTC
+++ source/Host/common/Host.cpp
@@ -27,6 +27,7 @@
 #endif
 
 #if defined(__linux__) || defined(__FreeBSD__) ||                              \
+    defined(__DragonFly__) || \
     defined(__FreeBSD_kernel__) || defined(__APPLE__) ||                       \
     defined(__NetBSD__) || defined(__OpenBSD__) || defined(__EMSCRIPTEN__)
 #if !defined(__ANDROID__)
