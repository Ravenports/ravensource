--- include/LibreOfficeKit/LibreOfficeKitInit.h.orig	2025-06-05 10:22:59 UTC
+++ include/LibreOfficeKit/LibreOfficeKitInit.h
@@ -19,6 +19,7 @@
 #endif
 
 #if defined(__linux__) || defined (__FreeBSD__) ||\
+    defined (__DragonFly__) ||\
     defined(_WIN32) || defined(__APPLE__) || defined (__NetBSD__) ||\
     defined (__sun) || defined(__OpenBSD__) || defined(__EMSCRIPTEN__)
 
