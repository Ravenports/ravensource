--- src/mev.c.orig	2026-03-14 20:44:12 UTC
+++ src/mev.c
@@ -31,6 +31,22 @@
 #include <sys/select.h>
 #endif
 
+#if defined(__sun)
+#ifndef IMAXBEL
+#define IMAXBEL 0
+#endif
+
+static void cfmakeraw(struct termios *t) {
+    t->c_iflag &= ~(IMAXBEL | IXOFF | INPCK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
+    t->c_oflag &= ~OPOST;
+    t->c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON | ISIG | IEXTEN | NOFLSH | TOSTOP);
+    t->c_cflag &= ~(CSIZE | PARENB);
+    t->c_cflag |= CS8;
+    t->c_cc[VMIN] = 1;
+    t->c_cc[VTIME] = 0;
+}
+#endif
+
 enum {
 	tracking_x10 = 9,
 	tracking_mouse = 1000,
