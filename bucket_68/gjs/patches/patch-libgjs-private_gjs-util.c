--- libgjs-private/gjs-util.c.orig	2025-03-18 04:22:22 UTC
+++ libgjs-private/gjs-util.c
@@ -6,6 +6,10 @@
 
 #include <config.h>
 
+#if defined(__NetBSD__)
+#define uselocale(locale) NULL
+#endif
+
 #include <errno.h> /* for errno */
 #include <locale.h> /* for setlocale/duplocale/uselocale/newlocale/freelocale */
 #include <stdbool.h>
