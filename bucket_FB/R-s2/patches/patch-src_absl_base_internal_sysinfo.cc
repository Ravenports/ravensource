--- src/absl/base/internal/sysinfo.cc.orig	2021-09-21 13:18:13 UTC
+++ src/absl/base/internal/sysinfo.cc
@@ -31,7 +31,7 @@
 #include <sys/syscall.h>
 #endif
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/sysctl.h>
 #endif
 
