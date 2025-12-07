--- src/corelib/thread/qthread_unix.cpp.orig	2025-11-12 10:17:57 UTC
+++ src/corelib/thread/qthread_unix.cpp
@@ -34,7 +34,7 @@
 #  include <pthread_np.h>
 #endif
 
-#if defined(Q_OS_FREEBSD)
+#if (defined(Q_OS_FREEBSD) || defined(__MidnightBSD__)) && !defined(__DragonFly__)
 #  include <sys/cpuset.h>
 #elif defined(Q_OS_BSD4)
 #  include <sys/sysctl.h>
@@ -549,7 +549,7 @@ int QThread::idealThreadCount() noexcept
     } else {
         cores = (int)psd.psd_proc_cnt;
     }
-#elif (defined(Q_OS_LINUX) && !defined(Q_OS_ANDROID)) || defined(Q_OS_FREEBSD)
+#elif (defined(Q_OS_LINUX) && !defined(Q_OS_ANDROID)) || (defined(Q_OS_FREEBSD) && !defined(__DragonFly__))
     QT_WARNING_PUSH
 #  if defined(Q_CC_CLANG) && Q_CC_CLANG >= 1800
     QT_WARNING_DISABLE_CLANG("-Wvla-cxx-extension")
