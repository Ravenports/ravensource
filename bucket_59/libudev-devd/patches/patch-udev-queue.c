--- udev-queue.c.orig	2023-01-16 23:20:51 UTC
+++ udev-queue.c
@@ -23,6 +23,7 @@
  * SUCH DAMAGE.
  */
 
+#include "config.h"
 #include "utils.h"
 
 #include <sys/socket.h>
