--- tests/pixbuf-randomly-modified.c.orig	2021-04-09 14:44:51 UTC
+++ tests/pixbuf-randomly-modified.c
@@ -18,6 +18,9 @@
  */
 
 #include "config.h"
+#ifdef __sun__
+#define __EXTENSIONS__
+#endif
 #include "gdk-pixbuf/gdk-pixbuf.h"
 #include "glib.h"
 #include <stdio.h>
