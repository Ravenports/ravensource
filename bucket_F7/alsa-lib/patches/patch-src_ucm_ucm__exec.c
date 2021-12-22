--- src/ucm/ucm_exec.c.orig	2021-12-09 13:17:59 UTC
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
 
 static pthread_mutex_t fork_lock = PTHREAD_MUTEX_INITIALIZER;
 
