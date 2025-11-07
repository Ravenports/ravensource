--- glib/glib-unix.c.orig	2025-10-21 14:26:53 UTC
+++ glib/glib-unix.c
@@ -49,6 +49,9 @@
 #include <stdlib.h>   /* for fdwalk */
 #include <string.h>
 #include <sys/types.h>
+#ifdef __sun
+#define _POSIX_PTHREAD_SEMANTICS 1
+#endif
 #include <pwd.h>
 #include <unistd.h>
 
