--- extcap.c.orig	2023-05-24 17:33:51 UTC
+++ extcap.c
@@ -22,6 +22,7 @@
 #include <process.h>
 #include <time.h>
 #else
+#include <sys/wait.h>
 /* Include for unlink */
 #include <unistd.h>
 #endif
