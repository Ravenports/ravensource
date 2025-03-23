--- glib/giounix.c.orig	2025-02-20 13:08:16 UTC
+++ glib/giounix.c
@@ -33,7 +33,9 @@
 
 #include "config.h"
 
+#ifndef __sun__
 #define _POSIX_SOURCE		/* for SSIZE_MAX */
+#endif
 
 #include <sys/types.h>
 #include <sys/stat.h>
