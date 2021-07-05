--- src/common/common.h.orig	2021-05-29 15:05:05 UTC
+++ src/common/common.h
@@ -262,7 +262,7 @@
 /*****************************************************
 * FreeBSD for Intel platforms
 *****************************************************/
-#ifdef FREEBSD
+#if defined(FREEBSD) || defined(DRAGONFLY)
 
 #define FB_OS OsFreeBsd
 #define FB_CC CcGcc
@@ -286,7 +286,7 @@
 #define USE_POSIX_THREADS
 #endif
 
-#endif /* FREEBSD */
+#endif /* FREEBSD or DRAGONFLY */
 
 /*****************************************************
 * NetBSD
