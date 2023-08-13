--- absl/base/internal/sysinfo.cc.orig	2023-08-07 18:40:00 UTC
+++ absl/base/internal/sysinfo.cc
@@ -26,11 +26,11 @@
 #include <unistd.h>
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__DragonFly__)
 #include <sys/syscall.h>
 #endif
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/sysctl.h>
 #endif
 
@@ -432,6 +432,12 @@ pid_t GetTID() {
   return static_cast<pid_t>(tid);
 }
 
+#elif defined(__DragonFly__)
+
+pid_t GetTID() {
+  return syscall(SYS_lwp_gettid);
+}
+
 #elif defined(__native_client__)
 
 pid_t GetTID() {
