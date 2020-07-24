--- pr/src/misc/prnetdb.c.orig	2020-07-23 13:54:12 UTC
+++ pr/src/misc/prnetdb.c
@@ -73,11 +73,6 @@ PRLock *_pr_dnsLock = NULL;
 #define _PR_HAVE_GETPROTO_R_INT
 #endif
 
-#if __FreeBSD_version >= 602000
-#define _PR_HAVE_GETPROTO_R
-#define _PR_HAVE_5_ARG_GETPROTO_R
-#endif
-
 /* BeOS has glibc but not the glibc-style getprotobyxxx_r functions. */
 #if (defined(__GLIBC__) && __GLIBC__ >= 2)
 #define _PR_HAVE_GETPROTO_R
@@ -304,7 +299,7 @@ _pr_QueryNetIfs(void)
 }
 
 #elif (defined(DARWIN) && defined(HAVE_GETIFADDRS)) || defined(FREEBSD) \
-    || defined(NETBSD) || defined(OPENBSD)
+    || defined(NETBSD) || defined(OPENBSD) || defined(DRAGONFLY)
 
 /*
  * Use the BSD getifaddrs function.
