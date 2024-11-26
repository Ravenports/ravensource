--- src/lftp_pty.c.orig	2022-02-24 16:27:37 UTC
+++ src/lftp_pty.c
@@ -33,8 +33,12 @@
 #ifdef HAVE_TERMIOS_H
 # include <termios.h>
 #endif
-#ifdef HAVE_UTIL_H
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+# include <libutil.h>
+#else
+# ifdef HAVE_UTIL_H
 # include <util.h>
+# endif
 #endif
 #ifdef HAVE_PTY_H
 # include <pty.h>
