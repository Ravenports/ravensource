--- pr/include/md/_pth.h.orig	2019-03-07 10:04:05 UTC
+++ pr/include/md/_pth.h
@@ -86,7 +86,7 @@
  */
 #if defined(IRIX) || defined(OSF1) || defined(AIX) || defined(SOLARIS) \
 	|| defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
-	|| defined(HPUX) || defined(FREEBSD) \
+	|| defined(HPUX) || defined(FREEBSD) || defined(__DragonFly__) \
 	|| defined(NETBSD) || defined(OPENBSD) || defined(BSDI) \
 	|| defined(NTO) || defined(DARWIN) \
 	|| defined(UNIXWARE) || defined(RISCOS)	|| defined(SYMBIAN)
@@ -140,7 +140,7 @@
 #define PT_PRIO_MIN            sched_get_priority_min(SCHED_OTHER)
 #define PT_PRIO_MAX            sched_get_priority_max(SCHED_OTHER)
 #elif defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
-	|| defined(FREEBSD) || defined(SYMBIAN)
+	|| defined(FREEBSD) || defined(SYMBIAN) || defined(__DragonFly__)
 #define PT_PRIO_MIN            sched_get_priority_min(SCHED_OTHER)
 #define PT_PRIO_MAX            sched_get_priority_max(SCHED_OTHER)
 #elif defined(NTO)
@@ -197,6 +197,7 @@ extern int (*_PT_aix_yield_fcn)();
 #elif defined(HPUX) || defined(SOLARIS) \
 	|| defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
 	|| defined(FREEBSD) || defined(NETBSD) || defined(OPENBSD) \
+	|| defined(__DragonFly__) \
 	|| defined(BSDI) || defined(NTO) || defined(DARWIN) \
 	|| defined(UNIXWARE) || defined(RISCOS) || defined(SYMBIAN)
 #define _PT_PTHREAD_YIELD()            	sched_yield()
