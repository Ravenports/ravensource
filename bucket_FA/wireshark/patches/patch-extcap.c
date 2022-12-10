--- extcap.c.orig	2022-12-07 18:06:21 UTC
+++ extcap.c
@@ -22,6 +22,7 @@
 #include <process.h>
 #include <time.h>
 #else
+#include <sys/wait.h>
 /* Include for unlink */
 #include <unistd.h>
 #endif
