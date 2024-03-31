--- gio/glocalfileinfo.c.orig	2024-03-07 21:35:05 UTC
+++ gio/glocalfileinfo.c
@@ -24,6 +24,10 @@
 
 #include "config.h"
 
+#ifdef __sun__
+#  define	_POSIX_PTHREAD_SEMANTICS 1
+#endif
+
 #include <glib.h>
 
 #ifdef HAVE_SYS_TIME_H
