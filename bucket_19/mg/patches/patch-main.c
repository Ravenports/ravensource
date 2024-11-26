--- main.c.orig	2023-05-01 15:27:50 UTC
+++ main.c
@@ -20,6 +20,8 @@
 #if HAVE_PTY_H
 #include <pty.h>
 #include <utmp.h>
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+#include <libutil.h>
 #elif HAVE_UTIL_H
 #include <util.h>
 #endif
