--- pr/src/misc/prnetdb.c.orig	2019-10-22 17:25:38 UTC
+++ pr/src/misc/prnetdb.c
@@ -73,6 +73,11 @@ PRLock *_pr_dnsLock = NULL;
 #define _PR_HAVE_GETPROTO_R_INT
 #endif
 
+#if defined(DRAGONFLY)
+#define _PR_HAVE_GETPROTO_R
+#define _PR_HAVE_5_ARG_GETPROTO_R
+#endif
+
 /* BeOS has glibc but not the glibc-style getprotobyxxx_r functions. */
 #if (defined(__GLIBC__) && __GLIBC__ >= 2)
 #define _PR_HAVE_GETPROTO_R
@@ -299,7 +304,7 @@ _pr_QueryNetIfs(void)
 }
 
 #elif (defined(DARWIN) && defined(HAVE_GETIFADDRS)) || defined(FREEBSD) \
-    || defined(NETBSD) || defined(OPENBSD)
+    || defined(NETBSD) || defined(OPENBSD) || defined(DRAGONFLY)
 
 /*
  * Use the BSD getifaddrs function.
