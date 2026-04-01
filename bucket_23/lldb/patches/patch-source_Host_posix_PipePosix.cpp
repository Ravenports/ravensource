--- source/Host/posix/PipePosix.cpp.orig	2026-03-23 18:46:22 UTC
+++ source/Host/posix/PipePosix.cpp
@@ -34,6 +34,7 @@ enum PIPES { READ, WRITE }; // Constants
 // pipe2 is supported by a limited set of platforms
 // TODO: Add more platforms that support pipe2.
 #if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) ||       \
+    defined(__DragonFly__) ||\
     defined(__OpenBSD__)
 #define PIPE2_SUPPORTED 1
 #else
