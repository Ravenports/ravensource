--- src/corelib/thread/qthread_unix.cpp.orig	2024-10-01 10:46:30 UTC
+++ src/corelib/thread/qthread_unix.cpp
@@ -37,7 +37,7 @@
 #include <sched.h>
 #include <errno.h>
 
-#if defined(Q_OS_FREEBSD)
+#if (defined(Q_OS_FREEBSD) || defined(__MidnightBSD__)) && !defined(__DragonFly__)
 #  include <sys/cpuset.h>
 #elif defined(Q_OS_BSD4)
 #  include <sys/sysctl.h>
@@ -429,8 +429,8 @@ int QThread::idealThreadCount() noexcept
     } else {
         cores = (int)psd.psd_proc_cnt;
     }
-#elif (defined(Q_OS_LINUX) && !defined(Q_OS_ANDROID)) || defined(Q_OS_FREEBSD)
-#  if defined(Q_OS_FREEBSD) && !defined(CPU_COUNT_S)
+#elif defined(__MidnightBSD__) || (defined(Q_OS_LINUX) && !defined(Q_OS_ANDROID)) || defined(Q_OS_FREEBSD) && !defined(__DragonFly__)
+#  if (defined(Q_OS_FREEBSD) || defined(__MidnightBSD__)) && !defined(CPU_COUNT_S)
 #    define CPU_COUNT_S(setsize, cpusetp)   ((int)BIT_COUNT(setsize, cpusetp))
     // match the Linux API for simplicity
     using cpu_set_t = cpuset_t;
