--- extcap.c.orig	2020-01-15 18:12:58 UTC
+++ extcap.c
@@ -21,6 +21,7 @@
 #include <process.h>
 #include <time.h>
 #else
+#include <sys/wait.h>
 /* Include for unlink */
 #include <unistd.h>
 #endif
