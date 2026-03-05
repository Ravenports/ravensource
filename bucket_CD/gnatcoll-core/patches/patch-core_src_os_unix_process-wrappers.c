--- core/src/os/unix/process-wrappers.c.orig	2025-11-28 12:36:47 UTC
+++ core/src/os/unix/process-wrappers.c
@@ -29,6 +29,11 @@
 #include <sys/wait.h>
 #include <sys/time.h>
 #include <signal.h>
+#include <string.h>
+#ifdef __NetBSD__
+#include <sys/select.h>
+#include <sys/time.h>
+#endif
 
 typedef long long int sint_64;
 
