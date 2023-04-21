--- udev-hwdb.c.orig	2023-01-16 23:20:51 UTC
+++ udev-hwdb.c
@@ -23,6 +23,7 @@
  * SUCH DAMAGE.
  */
 
+#include "config.h"
 #include "utils.h"
 
 #include <errno.h>
