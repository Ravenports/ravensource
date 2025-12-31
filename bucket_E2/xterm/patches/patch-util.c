--- util.c.orig	2025-12-12 01:16:39 UTC
+++ util.c
@@ -54,6 +54,10 @@
 
 /* util.c */
 
+#ifdef __linux__
+#define _XOPEN_SOURCE
+#endif
+
 #include <xterm.h>
 
 #include <data.h>
