--- deps/v8/third_party/abseil-cpp/absl/base/internal/sysinfo.cc.orig	2025-09-25 14:43:14 UTC
+++ deps/v8/third_party/abseil-cpp/absl/base/internal/sysinfo.cc
@@ -26,11 +26,19 @@
 #include <unistd.h>
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__DragonFly__)
 #include <sys/syscall.h>
 #endif
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__NetBSD__)
+#include <lwp.h> // For _lwp_self()
+#endif
+
+#if defined(__MidnightBSD__)
+#include <pthread_np.h>
+#endif
+
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/sysctl.h>
 #endif
 
@@ -456,6 +464,24 @@ pid_t GetTID() { return getthrid(); }
 
 pid_t GetTID() { return static_cast<pid_t>(_lwp_self()); }
 
+#elif defined(__DragonFly__)
+
+pid_t GetTID() {
+  return syscall(SYS_lwp_gettid);
+}
+
+#elif defined(__NetBSD__)
+
+pid_t GetTID() {
+  return static_cast<pid_t>(_lwp_self());
+}
+
+#elif defined(__MidnightBSD__)
+
+pid_t GetTID() {
+  return static_cast<pid_t>(pthread_getthreadid_np());
+}
+
 #elif defined(__native_client__)
 
 pid_t GetTID() {
