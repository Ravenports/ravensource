--- util.c.orig	2024-12-01 20:14:26 UTC
+++ util.c
@@ -54,6 +54,10 @@
 
 /* util.c */
 
+#ifdef __linux__
+#define _XOPEN_SOURCE
+#endif
+
 #include <xterm.h>
 
 #include <data.h>
