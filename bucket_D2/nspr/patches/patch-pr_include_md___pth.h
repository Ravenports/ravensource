--- pr/include/md/_pth.h.orig	2026-05-05 12:48:55 UTC
+++ pr/include/md/_pth.h
@@ -62,6 +62,7 @@
  */
 #if defined(AIX) || defined(SOLARIS) \
     || defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
+    || defined(__DragonFly__) \
     || defined(FREEBSD) || defined(NETBSD) || defined(OPENBSD) \
     || defined(NTO) || defined(DARWIN) \
     || defined(RISCOS)
@@ -103,6 +104,7 @@
 #define PT_PRIO_MIN            DEFAULT_PRIO
 #define PT_PRIO_MAX            DEFAULT_PRIO
 #elif defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
+    || defined(__DragonFly__) \
     || defined(FREEBSD)
 #define PT_PRIO_MIN            sched_get_priority_min(SCHED_OTHER)
 #define PT_PRIO_MAX            sched_get_priority_max(SCHED_OTHER)
@@ -145,6 +147,7 @@ extern int (*_PT_aix_yield_fcn)();
 #define _PT_PTHREAD_YIELD()         (*_PT_aix_yield_fcn)()
 #elif defined(SOLARIS) \
     || defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
+    || defined(__DragonFly__) \
     || defined(FREEBSD) || defined(NETBSD) || defined(OPENBSD) \
     || defined(NTO) || defined(DARWIN) \
     || defined(RISCOS)
