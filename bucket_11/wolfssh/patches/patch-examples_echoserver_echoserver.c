--- examples/echoserver/echoserver.c.orig	2026-04-20 16:06:58 UTC
+++ examples/echoserver/echoserver.c
@@ -71,9 +71,13 @@
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
