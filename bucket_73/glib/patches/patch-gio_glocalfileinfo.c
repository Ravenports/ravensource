--- gio/glocalfileinfo.c.orig	2024-05-08 15:29:04 UTC
+++ gio/glocalfileinfo.c
@@ -24,6 +24,10 @@
 
 #include "config.h"
 
+#ifdef __sun__
+#  define	_POSIX_PTHREAD_SEMANTICS 1
+#endif
+
 #include <glib.h>
 
 #ifdef HAVE_SYS_TIME_H
