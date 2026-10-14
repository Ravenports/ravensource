--- pr/include/md/_pth.h.orig	2026-08-05 04:57:49 UTC
+++ pr/include/md/_pth.h
@@ -61,6 +61,7 @@
  *   recursion ensues.
  */
 #if defined(AIX) || defined(SOLARIS) || defined(LINUX) || defined(__GNU__) || \
+    defined(__DragonFly__) ||                                                 \
     defined(__GLIBC__) || defined(FREEBSD) || defined(NETBSD) ||              \
     defined(OPENBSD) || defined(NTO) || defined(DARWIN) || defined(RISCOS)
 #define _PT_PTHREAD_INVALIDATE_THR_HANDLE(t) (t) = 0
@@ -86,6 +87,7 @@
  * These platforms don't have sigtimedwait()
  */
 #if (defined(AIX) && !defined(AIX4_3_PLUS)) || defined(LINUX) ||  \
+    defined(__DragonFly__) ||                                     \
     defined(__GNU__) || defined(__GLIBC__) || defined(FREEBSD) || \
     defined(NETBSD) || defined(OPENBSD) || defined(DARWIN)
 #define PT_NO_SIGTIMEDWAIT
@@ -100,6 +102,7 @@
 #define PT_PRIO_MIN DEFAULT_PRIO
 #define PT_PRIO_MAX DEFAULT_PRIO
 #elif defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) || \
+    defined(__DragonFly__) || \
     defined(FREEBSD)
 #define PT_PRIO_MIN sched_get_priority_min(SCHED_OTHER)
 #define PT_PRIO_MAX sched_get_priority_max(SCHED_OTHER)
@@ -139,6 +142,7 @@
 extern int (*_PT_aix_yield_fcn)();
 #define _PT_PTHREAD_YIELD() (*_PT_aix_yield_fcn)()
 #elif defined(SOLARIS) || defined(LINUX) || defined(__GNU__) ||  \
+    defined(__DragonFly__) ||                                    \
     defined(__GLIBC__) || defined(FREEBSD) || defined(NETBSD) || \
     defined(OPENBSD) || defined(NTO) || defined(DARWIN) || defined(RISCOS)
 #define _PT_PTHREAD_YIELD() sched_yield()
