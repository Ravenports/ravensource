--- src/app/app.cc.orig	2026-11-16 22:47:08 UTC
+++ src/app/app.cc
@@ -85,6 +85,22 @@ enum {
         VL3
 }; // Verbosity levels
 
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
 static void
 fprintln(FILE* fp,
          int level,
