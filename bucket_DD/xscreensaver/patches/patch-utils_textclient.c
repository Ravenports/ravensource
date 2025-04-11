--- utils/textclient.c.orig	2021-10-04 22:18:28 UTC
+++ utils/textclient.c
@@ -49,12 +49,14 @@
 # ifdef HAVE_PTY_H
 #  include <pty.h>
 # endif
-# ifdef HAVE_UTIL_H
-#  include <util.h>
-# endif
 # ifdef HAVE_SYS_TERMIOS_H
 #  include <sys/termios.h>
 # endif
+# if defined(__FreeBSD__) || defined(__DragonFly__)
+#  include <libutil.h>
+# elif defined(__NetBSD__)
+#  include <util.h>
+# endif
 #endif /* HAVE_FORKPTY */
 
 #undef DEBUG
