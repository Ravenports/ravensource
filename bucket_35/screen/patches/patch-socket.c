--- socket.c.orig	2019-10-01 22:08:00 UTC
+++ socket.c
@@ -26,6 +26,11 @@
  ****************************************************************
  */
 
+#ifdef __sun__ 
+#define _XPG6
+#define _XOPEN_SOURCE 500
+#endif
+
 #include "config.h"
 #include <stdbool.h>
 #include <string.h>
