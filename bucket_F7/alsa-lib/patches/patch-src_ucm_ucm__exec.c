--- src/ucm/ucm_exec.c.orig	2026-01-13 07:12:40 UTC
+++ src/ucm/ucm_exec.c
@@ -33,10 +33,11 @@
 #include <limits.h>
 #include <dirent.h>
 
-#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__sun)
 #include <signal.h>
-#if defined(__DragonFly__)
-#define environ NULL /* XXX */
+#include <unistd.h>
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+char *environ[] = { 0 };
 #else
 extern char **environ;
 #endif
