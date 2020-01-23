--- src/lib9/readcons.c.orig	2020-01-20 04:04:58 UTC
+++ src/lib9/readcons.c
@@ -2,7 +2,6 @@
 #define NOPLAN9DEFINES
 #include <libc.h>
 #include <termios.h>
-#include <sys/termios.h>
 
 static int
 rawx(int fd, int echoing)
