--- src/fg_internal.h.orig	2025-11-26 21:09:49.131780000 +0100
+++ src/fg_internal.h	2025-11-26 21:10:05.151605000 +0100
@@ -134,10 +134,6 @@
 #    include <time.h>
 #endif
 
-#if defined(__FreeBSD__) || defined(__NetBSD__)
-#    define HAVE_USB_JS 1
-#endif
-
 #if defined(_MSC_VER) || defined(__WATCOMC__)
 /* strdup() is non-standard, for all but POSIX-2001 */
 #define strdup   _strdup
