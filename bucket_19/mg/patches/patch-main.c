--- main.c.orig	2026-07-19 15:45:19 UTC
+++ main.c
@@ -20,6 +20,8 @@
 #if HAVE_PTY_H
 #include <pty.h>
 #include <utmp.h>
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+#include <libutil.h>
 #elif HAVE_UTIL_H
 #include <util.h>
 #elif HAVE_LIBUTIL_H
