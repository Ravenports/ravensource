--- boost/process/v2/posix/default_launcher.hpp.orig	2024-08-07 22:07:40 UTC
+++ boost/process/v2/posix/default_launcher.hpp
@@ -29,7 +29,7 @@
 #include <unistd.h>
 
 
-#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__MACH__)
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__MACH__) || defined(__DragonFly__) || defined(__sun)
 extern "C" { extern char **environ; }
 #endif
 
