--- src/vte.cc.orig	2024-10-19 19:25:25 UTC
+++ src/vte.cc
@@ -34,6 +34,13 @@
 #if __has_include(<sys/stream.h>)
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
