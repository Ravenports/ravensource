--- include/u.h.orig	2020-08-16 00:46:23 UTC
+++ include/u.h
@@ -38,6 +38,15 @@ extern "C" {
 #	define _ALL_SOURCE
 #	undef HAS_SYS_TERMIOS
 #endif
+#if defined(__DragonFly__)
+#	undef HAS_SYS_TERMIOS
+#	include <sys/cdefs.h>
+	/* for strtoll */
+# undef __ISO_C_VISIBLE
+# define __ISO_C_VISIBLE 1999
+# undef __LONG_LONG_SUPPORTED
+# define __LONG_LONG_SUPPORTED
+#endif
 #define _LARGEFILE64_SOURCE 1
 #define _FILE_OFFSET_BITS 64
 
