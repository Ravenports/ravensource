--- src/corelib/thread/qthread_unix.cpp.orig	2026-05-11 20:54:55 UTC
+++ src/corelib/thread/qthread_unix.cpp
@@ -29,7 +29,7 @@
 #  include <pthread_np.h>
 #endif
 
-#if defined(Q_OS_FREEBSD)
+#if defined(Q_OS_FREEBSD) && !defined(__DragonFly__) && !defined(__MidnightBSD__)
 #  include <sys/cpuset.h>
 #elif defined(Q_OS_BSD4)
 #  include <sys/sysctl.h>
@@ -350,6 +350,8 @@ static void setCurrentThreadName(QThread
         pthread_setname_np(name);
 #  elif defined(Q_OS_OPENBSD)
         pthread_set_name_np(pthread_self(), name);
+#  elif defined(Q_OS_NETBSD)
+        pthread_setname_np(pthread_self(), name, nullptr);
 #  elif defined(Q_OS_QNX) || defined(Q_OS_BSD4)
         pthread_setname_np(pthread_self(), name);
 #  else
@@ -570,7 +572,7 @@ int QThread::idealThreadCount() noexcept
     } else {
         cores = (int)psd.psd_proc_cnt;
     }
-#elif (defined(Q_OS_LINUX) && !defined(Q_OS_ANDROID)) || defined(Q_OS_FREEBSD)
+#elif (defined(Q_OS_LINUX) && !defined(Q_OS_ANDROID)) || (defined(Q_OS_FREEBSD) && !defined(__DragonFly__) && !defined(__MidnightBSD__))
     QT_WARNING_PUSH
 #  if defined(Q_CC_CLANG) && Q_CC_CLANG >= 1800
     QT_WARNING_DISABLE_CLANG("-Wvla-cxx-extension")
