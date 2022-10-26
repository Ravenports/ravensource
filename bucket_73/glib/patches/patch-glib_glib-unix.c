--- glib/glib-unix.c.orig	2022-10-25 12:53:22 UTC
+++ glib/glib-unix.c
@@ -33,6 +33,9 @@
 
 #include <string.h>
 #include <sys/types.h>
+#ifdef __sun
+#define _POSIX_PTHREAD_SEMANTICS 1
+#endif
 #include <pwd.h>
 
 G_STATIC_ASSERT (sizeof (ssize_t) == GLIB_SIZEOF_SSIZE_T);
