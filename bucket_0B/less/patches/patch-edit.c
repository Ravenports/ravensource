--- edit.c.orig	2023-05-03 18:43:01 UTC
+++ edit.c
@@ -16,9 +16,7 @@
 #if HAVE_SYS_WAIT_H
 #include <sys/wait.h>
 #endif
-#if OS2
 #include <signal.h>
-#endif
 
 public int fd0 = 0;
 
