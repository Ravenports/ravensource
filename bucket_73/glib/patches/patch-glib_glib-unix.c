--- glib/glib-unix.c.orig	2021-02-04 18:25:09 UTC
+++ glib/glib-unix.c
@@ -31,6 +31,9 @@
 
 #include <string.h>
 #include <sys/types.h>
+#ifdef __sun
+#define _POSIX_PTHREAD_SEMANTICS 1
+#endif
 #include <pwd.h>
 
 /**
