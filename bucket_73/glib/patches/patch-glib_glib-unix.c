--- glib/glib-unix.c.orig	2023-09-08 13:42:18 UTC
+++ glib/glib-unix.c
@@ -29,6 +29,9 @@
 
 #include <string.h>
 #include <sys/types.h>
+#ifdef __sun
+#define _POSIX_PTHREAD_SEMANTICS 1
+#endif
 #include <pwd.h>
 
 G_STATIC_ASSERT (sizeof (ssize_t) == GLIB_SIZEOF_SSIZE_T);
