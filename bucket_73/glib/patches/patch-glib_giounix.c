--- glib/giounix.c.orig	2022-12-21 21:16:58 UTC
+++ glib/giounix.c
@@ -33,7 +33,9 @@
 
 #include "config.h"
 
+#ifndef __sun__
 #define _POSIX_SOURCE		/* for SSIZE_MAX */
+#endif
 
 #include <sys/types.h>
 #include <sys/stat.h>
