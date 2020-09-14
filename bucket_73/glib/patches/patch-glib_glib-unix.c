--- glib/glib-unix.c.orig	2020-09-10 10:42:41 UTC
+++ glib/glib-unix.c
@@ -31,6 +31,9 @@
 
 #include <string.h>
 #include <sys/types.h>
+#ifdef __sun
+#define _POSIX_PTHREAD_SEMANTICS 1
+#endif
 #include <pwd.h>
 
 /**
