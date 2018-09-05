--- pr/src/pthreads/ptsynch.c.orig	2018-09-05 01:03:20 UTC
+++ pr/src/pthreads/ptsynch.c
@@ -912,6 +912,7 @@ PR_IMPLEMENT(PRStatus) PR_DeleteSemaphor
  */
 #if (defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)) \
     || (defined(FREEBSD) && __FreeBSD_version < 1200059) \
+    || defined(__DragonFly__) \
     || defined(OPENBSD) || defined(BSDI) \
     || defined(DARWIN) || defined(SYMBIAN)
 /* union semun is defined by including <sys/sem.h> */
