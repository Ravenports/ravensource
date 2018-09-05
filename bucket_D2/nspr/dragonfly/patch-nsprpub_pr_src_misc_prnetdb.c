--- pr/src/misc/prnetdb.c.orig	2018-09-05 01:03:20 UTC
+++ pr/src/misc/prnetdb.c
@@ -81,6 +81,11 @@ PRLock *_pr_dnsLock = NULL;
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
@@ -298,7 +303,7 @@ _pr_QueryNetIfs(void)
 }
 
 #elif (defined(DARWIN) && defined(HAVE_GETIFADDRS)) || defined(FREEBSD) \
-    || defined(NETBSD) || defined(OPENBSD)
+    || defined(NETBSD) || defined(OPENBSD) || defined(DRAGONFLY)
 
 /*
  * Use the BSD getifaddrs function.
