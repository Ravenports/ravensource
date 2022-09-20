--- src/common/common.h.orig	2022-08-10 09:04:28 UTC
+++ src/common/common.h
@@ -264,7 +264,7 @@
 /*****************************************************
 * FreeBSD for Intel platforms
 *****************************************************/
-#ifdef FREEBSD
+#if defined(FREEBSD) || defined(DRAGONFLY)
 
 #define FB_OS OsFreeBsd
 #define FB_CC CcGcc
@@ -288,7 +288,7 @@
 #define USE_POSIX_THREADS
 #endif
 
-#endif /* FREEBSD */
+#endif /* FREEBSD or DRAGONFLY */
 
 /*****************************************************
 * NetBSD
