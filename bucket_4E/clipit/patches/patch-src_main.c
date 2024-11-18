--- src/main.c.orig	2020-06-11 05:33:56 UTC
+++ src/main.c
@@ -28,6 +28,7 @@
 
 #include <glib.h>
 #include <stdlib.h>
+#include <sys/stat.h>
 #include <gtk/gtk.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
