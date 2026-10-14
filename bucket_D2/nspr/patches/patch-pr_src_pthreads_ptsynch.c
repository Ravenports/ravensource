--- pr/src/pthreads/ptsynch.c.orig	2026-08-05 04:57:49 UTC
+++ pr/src/pthreads/ptsynch.c
@@ -929,6 +929,7 @@ PR_DeleteSemaphore(const char* name)
  */
 #if (defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)) || \
     (defined(FREEBSD) && __FreeBSD_version < 1200059) ||            \
+    defined(__DragonFly__) ||                                       \
     defined(OPENBSD) || defined(DARWIN)
 /* union semun is defined by including <sys/sem.h> */
 #else
