--- src/ucm/ucm_exec.c.orig	2022-10-24 08:17:27 UTC
+++ src/ucm/ucm_exec.c
@@ -32,6 +32,12 @@
 #include <sys/wait.h>
 #include <limits.h>
 #include <dirent.h>
+#include <unistd.h>
+#include <signal.h>
+
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+char *environ[] = { 0 };
+#endif 
 
 #if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <signal.h>
