--- socket.c.orig	Mon Aug 26 19:27:26 2019
+++ socket.c	Mon Aug 26 20:13:11 2019
@@ -26,6 +26,9 @@
  ****************************************************************
  */
 
+#define _XPG6
+#define _XOPEN_SOURCE 500
+
 #include "config.h"
 #include <stdbool.h>
 #include <string.h>
