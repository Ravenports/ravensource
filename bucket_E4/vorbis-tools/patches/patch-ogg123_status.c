--- ogg123/status.c.orig	2025-04-13 06:11:17 UTC
+++ ogg123/status.c
@@ -26,6 +26,9 @@
 #ifdef HAVE_UNISTD_H
 #include <sys/ioctl.h>
 #include <unistd.h>
+# ifdef __sun__
+# include <sys/termios.h>
+# endif
 #endif
 
 #ifdef HAVE_FCNTL_H
