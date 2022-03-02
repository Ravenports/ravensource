--- pty.c.orig	2022-01-28 14:06:02 UTC
+++ pty.c
@@ -35,6 +35,13 @@
 #include <utils.h>  /* for openpty() */
 #endif
 
+#if defined(__DragonFly__)
+#include <util.h>  /* for openpty() */
+#endif
+#if defined(__FreeBSD__)
+#include <libutil.h>  /* for openpty() */
+#endif
+
 #include "config.h"
 #include "screen.h"
 
