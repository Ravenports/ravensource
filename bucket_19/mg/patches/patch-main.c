--- main.c.orig	2023-05-01 15:27:50 UTC
+++ main.c
@@ -20,7 +20,7 @@
 #if HAVE_PTY_H
 #include <pty.h>
 #include <utmp.h>
-#elif HAVE_UTIL_H
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #include <util.h>
 #endif
 
