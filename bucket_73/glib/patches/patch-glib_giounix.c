--- glib/giounix.c.orig	2021-03-18 13:28:31 UTC
+++ glib/giounix.c
@@ -31,7 +31,9 @@
 
 #include "config.h"
 
+#ifndef __sun__
 #define _POSIX_SOURCE		/* for SSIZE_MAX */
+#endif
 
 #include <sys/types.h>
 #include <sys/stat.h>
