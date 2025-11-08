--- pr/src/pthreads/ptio.c.orig	2025-11-05 10:29:01 UTC
+++ pr/src/pthreads/ptio.c
@@ -181,6 +181,7 @@ static PRBool _pr_ipv6_v6only_on_by_defa
 #  elif (defined(AIX) && !defined(AIX4_1)) || defined(SOLARIS) ||   \
       defined(HPUX10_30) || defined(HPUX11) || defined(LINUX) ||    \
       defined(__GNU__) || defined(__GLIBC__) || defined(FREEBSD) || \
+      defined(__DragonFly__) || \
       defined(NETBSD) || defined(OPENBSD) || defined(NTO) ||        \
       defined(DARWIN) || defined(RISCOS)
 #    define _PRSelectFdSetArg_t fd_set*
@@ -3105,6 +3106,7 @@ static PRIOMethods _pr_socketpollfd_meth
 #  if defined(SOLARIS) || defined(LINUX) ||     \
       defined(__GNU__) || defined(__GLIBC__) || defined(AIX) ||  \
       defined(FREEBSD) || defined(NETBSD) || defined(OPENBSD) || \
+      defined(__DragonFly__) || \
       defined(NTO) || defined(DARWIN) || defined(RISCOS)
 #    define _PR_FCNTL_FLAGS O_NONBLOCK
 #  else
@@ -4385,6 +4387,7 @@ PR_Select(PRInt32 unused, PR_fd_set* pr_
 
   if (timeout == PR_INTERVAL_NO_TIMEOUT) {
     tvp = NULL;
+    start = 0; /* Not needed, but shuts down a warning */
   } else {
     tv.tv_sec = (PRInt32)PR_IntervalToSeconds(timeout);
     tv.tv_usec = (PRInt32)PR_IntervalToMicroseconds(
