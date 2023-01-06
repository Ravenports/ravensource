--- app/load_save.c.orig	2014-08-24 15:46:01 UTC
+++ app/load_save.c
@@ -19,7 +19,13 @@
 
 /* so we get fdopen declared even when compiling with -ansi */
 #define _POSIX_C_SOURCE 200809L
-#define _BSD_SOURCE 1 /* to get the prototype for fchmod() */
+
+/* to get the prototype for fchmod() */
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE 1
+#else
+#define _BSD_SOURCE 1
+#endif
 
 #include <sys/stat.h>
 #ifdef HAVE_UNISTD_H
