--- tools/vendor/abseil-cpp/absl/base/internal/sysinfo.cc.orig	2025-01-07 11:51:24 UTC
+++ tools/vendor/abseil-cpp/absl/base/internal/sysinfo.cc
@@ -30,7 +30,7 @@
 #include <sys/syscall.h>
 #endif
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/sysctl.h>
 #endif
 
