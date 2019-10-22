--- pr/src/pthreads/ptio.c.orig	2019-03-07 10:04:05 UTC
+++ pr/src/pthreads/ptio.c
@@ -182,6 +182,7 @@ static PRBool _pr_ipv6_v6only_on_by_defa
     || defined(HPUX10_30) || defined(HPUX11) \
     || defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
     || defined(FREEBSD) || defined(NETBSD) || defined(OPENBSD) \
+    || defined(__DragonFly__) \
     || defined(BSDI) || defined(NTO) || defined(DARWIN) \
     || defined(UNIXWARE) || defined(RISCOS) || defined(SYMBIAN)
 #define _PRSelectFdSetArg_t fd_set *
@@ -3355,6 +3356,7 @@ static PRIOMethods _pr_socketpollfd_meth
 #if defined(HPUX) || defined(OSF1) || defined(SOLARIS) || defined (IRIX) \
     || defined(LINUX) || defined(__GNU__) || defined(__GLIBC__) \
     || defined(AIX) || defined(FREEBSD) || defined(NETBSD) \
+    || defined(__DragonFly__) \
     || defined(OPENBSD) || defined(BSDI) || defined(NTO) \
     || defined(DARWIN) || defined(UNIXWARE) || defined(RISCOS) \
     || defined(SYMBIAN)
