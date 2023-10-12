--- udev-queue.c.orig	2023-10-09 09:18:22 UTC
+++ udev-queue.c
@@ -23,6 +23,7 @@
  * SUCH DAMAGE.
  */
 
+#include "config.h"
 #include "utils.h"
 
 #include <sys/socket.h>
