--- ui/cmdpipe.h.orig	2025-07-06 15:36:42 UTC
+++ ui/cmdpipe.h
@@ -20,6 +20,7 @@
 #define CMDPIPE_H
 
 #include "mtr.h"
+#include <sys/types.h> /* for pid_t */
 
 #define COMMAND_BUFFER_SIZE 4096
 #define PACKET_REPLY_BUFFER_SIZE 4096
