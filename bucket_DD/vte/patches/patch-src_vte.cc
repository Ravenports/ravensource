--- src/vte.cc.orig	2022-11-27 20:28:23 UTC
+++ src/vte.cc
@@ -33,6 +33,13 @@
 #ifdef HAVE_SYS_STREAM_H
 #include <sys/stream.h>
 #endif
+#ifdef HAVE_TERMIOS_H
+#include <termios.h>
+#endif
+#if defined(__sun__)
+#include <sys/ioccom.h>
+#include <sys/ptyvar.h>
+#endif
 
 #include <glib.h>
 #include <glib-unix.h>
