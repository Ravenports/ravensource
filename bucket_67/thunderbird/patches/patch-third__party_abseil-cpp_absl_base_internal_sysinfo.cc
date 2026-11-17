--- third_party/abseil-cpp/absl/base/internal/sysinfo.cc.orig	2026-11-07 02:40:20 UTC
+++ third_party/abseil-cpp/absl/base/internal/sysinfo.cc
@@ -45,11 +45,11 @@
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
 
@@ -449,6 +449,10 @@ pid_t GetTID() {
   return static_cast<pid_t>(tid);
 }
 
+#elif defined(__DragonFly__)
+
+pid_t GetTID() { return syscall(SYS_lwp_gettid); }
+
 #elif defined(__FreeBSD__)
 
 pid_t GetTID() { return static_cast<pid_t>(pthread_getthreadid_np()); }
