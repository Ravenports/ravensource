--- socket.c.orig	2022-01-28 14:06:02 UTC
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
