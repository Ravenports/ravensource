--- ipc/chromium/src/base/platform_thread_posix.cc.orig	2019-02-27 22:18:23 UTC
+++ ipc/chromium/src/base/platform_thread_posix.cc
@@ -16,6 +16,8 @@
 #elif defined(OS_LINUX)
 #include <sys/syscall.h>
 #include <sys/prctl.h>
+#elif defined(OS_DRAGONFLY)
+#include <sys/lwp.h>
 #endif
 
 #if !defined(OS_MACOSX)
