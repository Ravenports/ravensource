--- src/cmd/9term/bsdpty.c.orig	2020-01-20 04:04:58 UTC
+++ src/cmd/9term/bsdpty.c
@@ -5,7 +5,6 @@
 #include <errno.h>
 #include <grp.h>
 #include <termios.h>
-#include <sys/termios.h>
 #ifdef __linux__
 #include <pty.h>
 #endif
