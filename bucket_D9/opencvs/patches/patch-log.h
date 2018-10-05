--- log.h.orig	2018-09-29 16:14:00 UTC
+++ log.h
@@ -28,6 +28,7 @@
 #define LOG_H
 
 #include <stdarg.h>
+#include <sys/types.h>
 
 /* log priority levels */
 #define LP_NOTICE	0
