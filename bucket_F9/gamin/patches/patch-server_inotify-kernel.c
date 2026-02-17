--- server/inotify-kernel.c.orig	2008-11-12 20:45:28 UTC
+++ server/inotify-kernel.c
@@ -25,6 +25,9 @@
 #include "inotify-kernel.h"
 
 #include <sys/inotify.h>
+#if defined(__sun__)
+#include <sys/filio.h>
+#endif
 
 /* Timings for pairing MOVED_TO / MOVED_FROM events */
 #define PROCESS_EVENTS_TIME 1000 /* milliseconds (1 hz) */
