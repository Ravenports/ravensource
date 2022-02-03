--- glib/giounix.c.orig	2022-01-26 14:53:56 UTC
+++ glib/giounix.c
@@ -31,7 +31,9 @@
 
 #include "config.h"
 
+#ifndef __sun__
 #define _POSIX_SOURCE		/* for SSIZE_MAX */
+#endif
 
 #include <sys/types.h>
 #include <sys/stat.h>
