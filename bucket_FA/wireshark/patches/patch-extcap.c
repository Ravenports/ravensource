--- extcap.c.orig	2025-12-03 17:45:32 UTC
+++ extcap.c
@@ -22,6 +22,7 @@
 #include <process.h>
 #include <time.h>
 #else
+#include <sys/wait.h>
 /* Include for unlink */
 #include <unistd.h>
 #endif
