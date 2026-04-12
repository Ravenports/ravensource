--- src/dumpkeys.c.orig	2026-03-14 20:44:12 UTC
+++ src/dumpkeys.c
@@ -40,6 +40,22 @@
 #define MODE_APPLICATION_CURSOR_KEYS	1
 #define MODE_ALTERNATE_SCREEN		1047
 
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
 	normal = 0, application = 1
 } keypad_mode = normal, cursor_mode = normal;
