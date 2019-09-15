--- extcap.c.orig	2019-07-17 17:31:28 UTC
+++ extcap.c
@@ -21,6 +21,7 @@
 #include <process.h>
 #include <time.h>
 #else
+#include <sys/wait.h>
 /* Include for unlink */
 #include <unistd.h>
 #endif
