--- pr/src/misc/prnetdb.c.orig	2025-11-05 10:29:01 UTC
+++ pr/src/misc/prnetdb.c
@@ -72,11 +72,6 @@ PRLock* _pr_dnsLock = NULL;
 #  define _PR_HAVE_GETPROTO_R_INT
 #endif
 
-#if __FreeBSD_version >= 602000
-#  define _PR_HAVE_GETPROTO_R
-#  define _PR_HAVE_5_ARG_GETPROTO_R
-#endif
-
 /* BeOS has glibc but not the glibc-style getprotobyxxx_r functions. */
 #if (defined(__GLIBC__) && __GLIBC__ >= 2)
 #  define _PR_HAVE_GETPROTO_R
@@ -275,7 +270,7 @@ static void _pr_QueryNetIfs(void) {
 }
 
 #  elif (defined(DARWIN) && defined(HAVE_GETIFADDRS)) || defined(FREEBSD) || \
-      defined(NETBSD) || defined(OPENBSD)
+      defined(NETBSD) || defined(OPENBSD) || defined(__DragonFly__)
 
 /*
  * Use the BSD getifaddrs function.
