--- src/util/fy-utils.c.orig	2026-03-15 13:48:50 UTC
+++ src/util/fy-utils.c
@@ -32,6 +32,19 @@
 
 #include "xxhash.h"
 
+#if defined(__sun) || defined(__illumos__)
+#include <termios.h>
+
+static void cfmakeraw(struct termios *t)
+{
+    t->c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
+    t->c_oflag &= ~OPOST;
+    t->c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
+    t->c_cflag &= ~(CSIZE | PARENB);
+    t->c_cflag |= CS8;
+}
+#endif
+
 #if defined(__APPLE__) && (_POSIX_C_SOURCE < 200809L)
 
 /*
