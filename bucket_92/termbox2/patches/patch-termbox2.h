--- termbox2.h.orig	2026-11-07 04:53:32 UTC
+++ termbox2.h
@@ -60,6 +60,18 @@ SOFTWARE.
 extern "C" {
 #endif
 
+#if defined(__sun)
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
 // __ffi_start
 
 #define TB_VERSION_STR "2.7.0"
