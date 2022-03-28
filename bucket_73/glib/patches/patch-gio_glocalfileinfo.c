--- gio/glocalfileinfo.c.orig	2022-03-17 15:01:31 UTC
+++ gio/glocalfileinfo.c
@@ -22,6 +22,10 @@
 
 #include "config.h"
 
+#ifdef __sun__
+#  define	_POSIX_PTHREAD_SEMANTICS 1
+#endif
+
 #include <glib.h>
 
 #ifdef HAVE_SYS_TIME_H
