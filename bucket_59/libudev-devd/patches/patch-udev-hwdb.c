--- udev-hwdb.c.orig	2023-10-09 09:18:22 UTC
+++ udev-hwdb.c
@@ -23,6 +23,7 @@
  * SUCH DAMAGE.
  */
 
+#include "config.h"
 #include "utils.h"
 
 #include <errno.h>
