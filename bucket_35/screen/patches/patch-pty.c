--- pty.c.orig	2022-01-28 14:06:02 UTC
+++ pty.c
@@ -35,6 +35,10 @@
 #include <utils.h>  /* for openpty() */
 #endif
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <util.h>  /* for openpty() */
+#endif
+
 #include "config.h"
 #include "screen.h"
 
