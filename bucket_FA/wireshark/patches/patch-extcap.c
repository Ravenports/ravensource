--- extcap.c.orig	2020-02-26 20:17:45 UTC
+++ extcap.c
@@ -21,6 +21,7 @@
 #include <process.h>
 #include <time.h>
 #else
+#include <sys/wait.h>
 /* Include for unlink */
 #include <unistd.h>
 #endif
