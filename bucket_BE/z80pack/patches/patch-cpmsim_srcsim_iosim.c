--- cpmsim/srcsim/iosim.c.orig	2024-06-01 14:02:02 UTC
+++ cpmsim/srcsim/iosim.c
@@ -137,6 +137,10 @@
 #include "log.h"
 #include "rtc.h"
 
+#if !defined(O_ASYNC)
+#define O_ASYNC 0
+#endif
+
 #define BUFSIZE 256		/* max line length of command buffer */
 #define MAX_BUSY_COUNT 10	/* max counter to detect I/O busy waiting
 				   on the console status port */
