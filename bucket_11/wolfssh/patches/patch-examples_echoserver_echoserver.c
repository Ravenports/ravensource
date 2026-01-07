--- examples/echoserver/echoserver.c.orig	2025-10-20 21:46:33 UTC
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
