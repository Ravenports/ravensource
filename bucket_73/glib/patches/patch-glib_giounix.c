--- glib/giounix.c.orig	2018-08-30 17:12:08 UTC
+++ glib/giounix.c
@@ -32,6 +32,11 @@
 #include "config.h"
 
 #define _POSIX_SOURCE		/* for SSIZE_MAX */
+#ifdef __sun__
+#undef _XOPEN_SOURCE
+#define _XOPEN_SOURCE	600
+#define _XPG6
+#endif
 
 #include <sys/types.h>
 #include <sys/stat.h>
