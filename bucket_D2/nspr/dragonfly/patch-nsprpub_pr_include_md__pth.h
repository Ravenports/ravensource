--- pr/include/md/_pth.h.orig	2019-08-19 14:12:12 UTC
+++ pr/include/md/_pth.h
@@ -86,7 +86,7 @@
  */
 #if defined(AIX) || defined(SOLARIS) \
 	|| defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
-	|| defined(HPUX) || defined(FREEBSD) \
+	|| defined(HPUX) || defined(FREEBSD) || defined(__DragonFly__) \
 	|| defined(NETBSD) || defined(OPENBSD) || defined(BSDI) \
 	|| defined(NTO) || defined(DARWIN) \
 	|| defined(UNIXWARE) || defined(RISCOS)
@@ -133,7 +133,7 @@
 #define PT_PRIO_MIN            sched_get_priority_min(SCHED_OTHER)
 #define PT_PRIO_MAX            sched_get_priority_max(SCHED_OTHER)
 #elif defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
-	|| defined(FREEBSD)
+	|| defined(FREEBSD) || defined(__DragonFly__)
 #define PT_PRIO_MIN            sched_get_priority_min(SCHED_OTHER)
 #define PT_PRIO_MAX            sched_get_priority_max(SCHED_OTHER)
 #elif defined(NTO)
@@ -176,6 +176,7 @@ extern int (*_PT_aix_yield_fcn)();
 #elif defined(HPUX) || defined(SOLARIS) \
 	|| defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
 	|| defined(FREEBSD) || defined(NETBSD) || defined(OPENBSD) \
+	|| defined(__DragonFly__) \
 	|| defined(BSDI) || defined(NTO) || defined(DARWIN) \
 	|| defined(UNIXWARE) || defined(RISCOS)
 #define _PT_PTHREAD_YIELD()            	sched_yield()
