--- pr/include/md/_pth.h.orig	2025-11-05 10:29:01 UTC
+++ pr/include/md/_pth.h
@@ -63,6 +63,7 @@
  */
 #if defined(AIX) || defined(SOLARIS) \
     || defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
+    || defined(__DragonFly__) \
     || defined(FREEBSD) || defined(NETBSD) || defined(OPENBSD) \
     || defined(NTO) || defined(DARWIN) \
     || defined(RISCOS)
@@ -104,6 +105,7 @@
 #define PT_PRIO_MIN            DEFAULT_PRIO
 #define PT_PRIO_MAX            DEFAULT_PRIO
 #elif defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
+    || defined(__DragonFly__) \
     || defined(FREEBSD)
 #define PT_PRIO_MIN            sched_get_priority_min(SCHED_OTHER)
 #define PT_PRIO_MAX            sched_get_priority_max(SCHED_OTHER)
@@ -146,6 +148,7 @@ extern int (*_PT_aix_yield_fcn)();
 #define _PT_PTHREAD_YIELD()         (*_PT_aix_yield_fcn)()
 #elif defined(SOLARIS) \
     || defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
+    || defined(__DragonFly__) \
     || defined(FREEBSD) || defined(NETBSD) || defined(OPENBSD) \
     || defined(NTO) || defined(DARWIN) \
     || defined(RISCOS)
