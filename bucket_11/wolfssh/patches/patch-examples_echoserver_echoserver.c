--- examples/echoserver/echoserver.c.orig	2026-10-05 17:53:17 UTC
+++ examples/echoserver/echoserver.c
@@ -78,9 +78,13 @@
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
