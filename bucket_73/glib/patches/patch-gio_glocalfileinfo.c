--- gio/glocalfileinfo.c.orig	2019-09-05 16:56:48 UTC
+++ gio/glocalfileinfo.c
@@ -22,6 +22,10 @@
 
 #include "config.h"
 
+#ifdef __sun__
+#  define	_POSIX_PTHREAD_SEMANTICS 1
+#endif
+
 #include <glib.h>
 
 #ifdef HAVE_SYS_TIME_H
