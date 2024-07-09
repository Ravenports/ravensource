--- glib/glib-unix.c.orig	2024-07-08 14:03:15 UTC
+++ glib/glib-unix.c
@@ -48,6 +48,9 @@
 #include <stdlib.h>   /* for fdwalk */
 #include <string.h>
 #include <sys/types.h>
+#ifdef __sun
+#define _POSIX_PTHREAD_SEMANTICS 1
+#endif
 #include <pwd.h>
 #include <unistd.h>
 
