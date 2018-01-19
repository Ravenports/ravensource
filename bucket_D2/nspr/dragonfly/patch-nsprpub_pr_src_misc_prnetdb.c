--- pr/src/misc/prnetdb.c.orig	2018-01-19 15:06:41 UTC
+++ pr/src/misc/prnetdb.c
@@ -77,6 +77,11 @@ PRLock *_pr_dnsLock = NULL;
 #define _PR_HAVE_GETPROTO_R_INT
 #endif
 
+#if defined(DRAGONFLY)
+#define _PR_HAVE_GETPROTO_R
+#define _PR_HAVE_5_ARG_GETPROTO_R
+#endif
+
 /* BeOS has glibc but not the glibc-style getprotobyxxx_r functions. */
 #if (defined(__GLIBC__) && __GLIBC__ >= 2 && !defined(XP_BEOS))
 #define _PR_HAVE_GETPROTO_R
@@ -294,7 +299,7 @@ _pr_QueryNetIfs(void)
 }
 
 #elif (defined(DARWIN) && defined(HAVE_GETIFADDRS)) || defined(FREEBSD) \
-    || defined(NETBSD) || defined(OPENBSD)
+    || defined(NETBSD) || defined(OPENBSD) || defined(DRAGONFLY)
 
 /*
  * Use the BSD getifaddrs function.
