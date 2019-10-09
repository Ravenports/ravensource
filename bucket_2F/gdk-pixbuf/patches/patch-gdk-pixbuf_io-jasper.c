--- gdk-pixbuf/io-jasper.c.orig	2019-10-08 10:44:10 UTC
+++ gdk-pixbuf/io-jasper.c
@@ -22,6 +22,10 @@
 #include <string.h>
 #include <errno.h>
 
+#ifdef __sun__
+#undef _XPG6
+#define __EXTENSIONS__
+#endif
 #include <jasper/jasper.h>
 
 #include <glib/gi18n-lib.h>
