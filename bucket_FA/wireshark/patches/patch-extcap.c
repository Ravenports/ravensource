--- extcap.c.orig	2024-03-27 16:32:47 UTC
+++ extcap.c
@@ -22,6 +22,7 @@
 #include <process.h>
 #include <time.h>
 #else
+#include <sys/wait.h>
 /* Include for unlink */
 #include <unistd.h>
 #endif
