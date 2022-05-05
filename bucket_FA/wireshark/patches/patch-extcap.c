--- extcap.c.orig	2022-03-23 16:58:59 UTC
+++ extcap.c
@@ -22,6 +22,7 @@
 #include <process.h>
 #include <time.h>
 #else
+#include <sys/wait.h>
 /* Include for unlink */
 #include <unistd.h>
 #endif
