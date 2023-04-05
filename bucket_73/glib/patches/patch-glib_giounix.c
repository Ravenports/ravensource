--- glib/giounix.c.orig	2023-03-22 11:28:01 UTC
+++ glib/giounix.c
@@ -33,7 +33,9 @@
 
 #include "config.h"
 
+#ifndef __sun__
 #define _POSIX_SOURCE		/* for SSIZE_MAX */
+#endif
 
 #include <sys/types.h>
 #include <sys/stat.h>
