--- pr/src/pthreads/ptsynch.c.orig	2019-10-22 17:25:38 UTC
+++ pr/src/pthreads/ptsynch.c
@@ -952,6 +952,7 @@ PR_IMPLEMENT(PRStatus) PR_DeleteSemaphor
  */
 #if (defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)) \
     || (defined(FREEBSD) && __FreeBSD_version < 1200059) \
+    || defined(__DragonFly__) \
     || defined(OPENBSD) || defined(BSDI) \
     || defined(DARWIN)
 /* union semun is defined by including <sys/sem.h> */
