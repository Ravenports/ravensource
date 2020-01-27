--- src/cmd/draw/mc.c.orig	2020-01-20 04:04:58 UTC
+++ src/cmd/draw/mc.c
@@ -9,7 +9,7 @@
  */
 #include	<u.h>
 #include	<sys/ioctl.h>
-#include	<sys/termios.h>
+#include	<termios.h>
 #include	<libc.h>
 #include	<draw.h>
 #include	<bio.h>
