--- src/vte.cc.orig	2022-09-23 18:46:10 UTC
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
