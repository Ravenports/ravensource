--- main.c.orig	2024-07-09 15:39:50 UTC
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
