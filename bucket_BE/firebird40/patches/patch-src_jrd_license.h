--- src/jrd/license.h.orig	2021-12-21 10:19:50 UTC
+++ src/jrd/license.h
@@ -110,7 +110,7 @@
 #define FB_PLATFORM     "LI"	// Linux on Intel
 #endif
 
-#ifdef FREEBSD
+#if defined(FREEBSD) || defined(DRAGONFLY)
 #define FB_PLATFORM     "FB"	// FreeBSD/i386
 #endif
 
