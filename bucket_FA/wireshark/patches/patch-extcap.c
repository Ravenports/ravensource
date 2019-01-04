--- extcap.c.orig	2018-11-28 18:28:19 UTC
+++ extcap.c
@@ -21,6 +21,7 @@
 #include <process.h>
 #include <time.h>
 #else
+#include <sys/wait.h>
 /* Include for unlink */
 #include <unistd.h>
 #endif
