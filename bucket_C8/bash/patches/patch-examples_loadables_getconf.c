$NetBSD: patch-examples_loadables_getconf.c,v 1.1 2022/10/04 12:45:31 kim Exp $

Handle _SC_RTSIG_MAX not being defined (NetBSD 9)

--- examples/loadables/getconf.c.orig	2021-12-03 16:46:22 UTC
+++ examples/loadables/getconf.c
@@ -846,7 +846,9 @@ static const struct conf vars[] =
 #ifdef _SC_TRACE_LOG
     { "_POSIX_TRACE_LOG", _SC_TRACE_LOG, SYSCONF },
 #endif
+#ifdef _SC_RTSIG_MAX
     { "RTSIG_MAX", _SC_RTSIG_MAX, SYSCONF },
+#endif
 #ifdef _SC_SEM_NSEMS_MAX
     { "SEM_NSEMS_MAX", _SC_SEM_NSEMS_MAX, SYSCONF },
 #endif
