--- pr/include/md/_pth.h.orig	2024-10-21 11:31:57 UTC
+++ pr/include/md/_pth.h
@@ -63,6 +63,7 @@
  */
 #if defined(AIX) || defined(SOLARIS) \
     || defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
+    || defined(__DragonFly__) \
     || defined(HPUX) || defined(FREEBSD) \
     || defined(NETBSD) || defined(OPENBSD) \
     || defined(NTO) || defined(DARWIN) \
@@ -109,6 +110,7 @@
 #define PT_PRIO_MIN            sched_get_priority_min(SCHED_OTHER)
 #define PT_PRIO_MAX            sched_get_priority_max(SCHED_OTHER)
 #elif defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
+    || defined(__DragonFly__) \
     || defined(FREEBSD)
 #define PT_PRIO_MIN            sched_get_priority_min(SCHED_OTHER)
 #define PT_PRIO_MAX            sched_get_priority_max(SCHED_OTHER)
@@ -151,6 +153,7 @@ extern int (*_PT_aix_yield_fcn)();
 #define _PT_PTHREAD_YIELD()         (*_PT_aix_yield_fcn)()
 #elif defined(HPUX) || defined(SOLARIS) \
     || defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
+    || defined(__DragonFly__) \
     || defined(FREEBSD) || defined(NETBSD) || defined(OPENBSD) \
     || defined(NTO) || defined(DARWIN) \
     || defined(RISCOS)
