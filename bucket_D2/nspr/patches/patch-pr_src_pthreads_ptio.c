--- pr/src/pthreads/ptio.c.orig	2026-08-05 04:57:49 UTC
+++ pr/src/pthreads/ptio.c
@@ -178,6 +178,7 @@ static PRBool _pr_ipv6_v6only_on_by_defa
 #define _PRSelectFdSetArg_t void*
 #elif (defined(AIX) && !defined(AIX4_1)) || defined(SOLARIS) ||   \
     defined(HPUX10_30) || defined(HPUX11) || defined(LINUX) ||    \
+    defined(__DragonFly__) ||                                     \
     defined(__GNU__) || defined(__GLIBC__) || defined(FREEBSD) || \
     defined(NETBSD) || defined(OPENBSD) || defined(NTO) ||        \
     defined(DARWIN) || defined(RISCOS)
@@ -3238,6 +3239,7 @@ static PRIOMethods _pr_socketpollfd_meth
 };
 
 #if defined(SOLARIS) || defined(LINUX) || defined(__GNU__) || \
+    defined(__DragonFly__) ||                                 \
     defined(__GLIBC__) || defined(AIX) || defined(FREEBSD) || \
     defined(NETBSD) || defined(OPENBSD) || defined(NTO) ||    \
     defined(DARWIN) || defined(RISCOS)
@@ -4624,6 +4626,7 @@ PR_Select(PRInt32 unused, PR_fd_set* pr_
 
     if (timeout == PR_INTERVAL_NO_TIMEOUT) {
         tvp = NULL;
+        start = 0; /* Not needed, but shuts down a warning */
     } else {
         tv.tv_sec = (PRInt32)PR_IntervalToSeconds(timeout);
         tv.tv_usec = (PRInt32)PR_IntervalToMicroseconds(
