--- util.c.orig	2023-05-09 07:57:05 UTC
+++ util.c
@@ -54,6 +54,10 @@
 
 /* util.c */
 
+#ifdef __linux__
+#define _XOPEN_SOURCE
+#endif
+
 #include <xterm.h>
 
 #include <data.h>
