--- ipc/chromium/src/base/process_util_posix.cc.orig	2025-05-12 16:04:52 UTC
+++ ipc/chromium/src/base/process_util_posix.cc
@@ -55,6 +55,10 @@
 #  define LOG_AND_ASSERT CHROMIUM_LOG(ERROR)
 #endif
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
+
 namespace base {
 
 ProcessId GetCurrentProcId() { return getpid(); }
