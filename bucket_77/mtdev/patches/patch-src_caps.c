--- src/caps.c.orig	2020-01-26 14:00:32 UTC
+++ src/caps.c
@@ -26,6 +26,9 @@
  *
  ****************************************************************************/
 
+#ifdef __NetBSD__
+#include <sys/ioctl.h>
+#endif
 #include "state.h"
 
 static const int SN_COORD = 250;	/* coordinate signal-to-noise ratio */
