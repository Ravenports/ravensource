--- gtk/gtkdatabox_ruler.c.orig	2021-04-20 00:39:22.000000000 +0200
+++ gtk/gtkdatabox_ruler.c	2022-12-31 23:15:51.244598000 +0100
@@ -33,6 +33,7 @@
 #include <glib/gprintf.h>
 
 #include <string.h>
+#include <sys/param.h>
 
 #define RULER_SIZE          20
 
