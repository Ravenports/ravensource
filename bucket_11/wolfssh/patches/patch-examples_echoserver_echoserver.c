--- examples/echoserver/echoserver.c.orig	2024-11-01 21:28:15 UTC
+++ examples/echoserver/echoserver.c
@@ -69,9 +69,13 @@
     #ifdef HAVE_PTY_H
         #include <pty.h>
     #endif
+  #if defined(__FreeBSD__) || defined(__DragonFly__)
+        #include <libutil.h>
+  #else
     #ifdef HAVE_UTIL_H
         #include <util.h>
     #endif
+  #endif
     #ifdef HAVE_TERMIOS_H
         #include <termios.h>
     #endif
