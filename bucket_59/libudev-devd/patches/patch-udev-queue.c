--- udev-queue.c.orig	2021-09-04 13:20:25 UTC
+++ udev-queue.c
@@ -23,6 +23,7 @@
  * SUCH DAMAGE.
  */
 
+#include "config.h"
 #include "utils.h"
 
 #include <sys/socket.h>
