--- src/ucm/ucm_exec.c.orig	2025-12-07 19:41:56 UTC
+++ src/ucm/ucm_exec.c
@@ -35,8 +35,9 @@
 
 #if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <signal.h>
-#if defined(__DragonFly__)
-#define environ NULL /* XXX */
+#include <unistd.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+char *environ[] = { 0 };
 #else
 extern char **environ;
 #endif
@@ -259,7 +260,7 @@ int uc_mgr_exec(const char *prog)
 
 		close(f);
 
-#if defined(_GNU_SOURCE)
+#if defined(__linux__)
 		close_range(3, maxfd, 0);
 #else
 		for (f = 3; f < maxfd; f++)
