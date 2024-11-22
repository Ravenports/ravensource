--- core/src/os/unix/process-wrappers.c.orig	2024-09-24 09:28:32 UTC
+++ core/src/os/unix/process-wrappers.c
@@ -28,6 +28,10 @@
 #include <unistd.h>
 #include <sys/wait.h>
 #include <signal.h>
+#ifdef __NetBSD__
+#include <sys/select.h>
+#include <sys/time.h>
+#endif
 
 typedef long long int sint_64;
 
