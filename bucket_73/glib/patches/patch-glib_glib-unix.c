--- glib/glib-unix.c.orig	2022-01-26 14:53:56 UTC
+++ glib/glib-unix.c
@@ -31,6 +31,9 @@
 
 #include <string.h>
 #include <sys/types.h>
+#ifdef __sun
+#define _POSIX_PTHREAD_SEMANTICS 1
+#endif
 #include <pwd.h>
 
 G_STATIC_ASSERT (sizeof (ssize_t) == GLIB_SIZEOF_SSIZE_T);
