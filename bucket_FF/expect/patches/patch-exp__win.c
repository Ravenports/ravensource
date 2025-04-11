--- exp_win.c.orig	2018-02-02 19:15:52 UTC
+++ exp_win.c
@@ -32,6 +32,9 @@ conflicts with sys/ioctl.h
 
 #ifdef HAVE_TERMIOS
 #  include <termios.h>
+#  if defined(__NetBSD__)
+#    include <sys/ioctl.h>
+#  endif
 #else
 #  include <sys/ioctl.h>
 #endif
