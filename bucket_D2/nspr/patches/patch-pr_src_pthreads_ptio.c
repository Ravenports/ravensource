--- pr/src/pthreads/ptio.c.orig	2022-05-25 21:34:56 UTC
+++ pr/src/pthreads/ptio.c
@@ -191,6 +191,7 @@ static PRBool _pr_ipv6_v6only_on_by_defa
     || defined(HPUX10_30) || defined(HPUX11) \
     || defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
     || defined(FREEBSD) || defined(NETBSD) || defined(OPENBSD) \
+    || defined(__DragonFly__) \
     || defined(BSDI) || defined(NTO) || defined(DARWIN) \
     || defined(UNIXWARE) || defined(RISCOS)
 #define _PRSelectFdSetArg_t fd_set *
@@ -3523,6 +3524,7 @@ static PRIOMethods _pr_socketpollfd_meth
 #if defined(HPUX) || defined(SOLARIS) \
     || defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
     || defined(AIX) || defined(FREEBSD) || defined(NETBSD) \
+    || defined(__DragonFly__) \
     || defined(OPENBSD) || defined(BSDI) || defined(NTO) \
     || defined(DARWIN) || defined(UNIXWARE) || defined(RISCOS)
 #define _PR_FCNTL_FLAGS O_NONBLOCK
@@ -5309,6 +5311,7 @@ PR_IMPLEMENT(PRInt32) PR_Select(
 
     if (timeout == PR_INTERVAL_NO_TIMEOUT) {
         tvp = NULL;
+        start = 0; /* Not needed, but shuts down a warning */
     } else {
         tv.tv_sec = (PRInt32)PR_IntervalToSeconds(timeout);
         tv.tv_usec = (PRInt32)PR_IntervalToMicroseconds(
