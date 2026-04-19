--- util.c.orig	2026-02-16 22:05:47.000000000 -0000
+++ util.c
@@ -54,6 +54,10 @@
 
 /* util.c */
 
+#ifdef __linux__
+#define _XOPEN_SOURCE
+#endif
+
 #include <xterm.h>
 
 #include <data.h>
