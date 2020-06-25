--- pr/include/md/_pth.h.orig	2020-06-24 13:26:09 UTC
+++ pr/include/md/_pth.h
@@ -86,6 +86,7 @@
  */
 #if defined(AIX) || defined(SOLARIS) \
     || defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
+    || defined(__DragonFly__) \
     || defined(HPUX) || defined(FREEBSD) \
     || defined(NETBSD) || defined(OPENBSD) || defined(BSDI) \
     || defined(NTO) || defined(DARWIN) \
@@ -133,6 +134,7 @@
 #define PT_PRIO_MIN            sched_get_priority_min(SCHED_OTHER)
 #define PT_PRIO_MAX            sched_get_priority_max(SCHED_OTHER)
 #elif defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
+    || defined(__DragonFly__) \
     || defined(FREEBSD)
 #define PT_PRIO_MIN            sched_get_priority_min(SCHED_OTHER)
 #define PT_PRIO_MAX            sched_get_priority_max(SCHED_OTHER)
@@ -175,6 +177,7 @@ extern int (*_PT_aix_yield_fcn)();
 #define _PT_PTHREAD_YIELD()         (*_PT_aix_yield_fcn)()
 #elif defined(HPUX) || defined(SOLARIS) \
     || defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
+    || defined(__DragonFly__) \
     || defined(FREEBSD) || defined(NETBSD) || defined(OPENBSD) \
     || defined(BSDI) || defined(NTO) || defined(DARWIN) \
     || defined(UNIXWARE) || defined(RISCOS)
