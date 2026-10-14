--- pr/src/misc/prnetdb.c.orig	2026-08-05 04:57:49 UTC
+++ pr/src/misc/prnetdb.c
@@ -70,11 +70,6 @@ PRLock* _pr_dnsLock = NULL;
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
@@ -279,6 +274,7 @@ _pr_QueryNetIfs(void)
 }
 
 #elif (defined(DARWIN) && defined(HAVE_GETIFADDRS)) || defined(FREEBSD) || \
+    defined(__DragonFly__) || \
     defined(NETBSD) || defined(OPENBSD)
 
 /*
