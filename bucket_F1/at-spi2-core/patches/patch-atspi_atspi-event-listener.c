--- atspi/atspi-event-listener.c.orig	2025-11-22 16:31:20 UTC
+++ atspi/atspi-event-listener.c
@@ -22,6 +22,9 @@
  * Boston, MA 02110-1301, USA.
  */
 
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE
+#endif
 #include "atspi-accessible-private.h"
 #include "atspi-private.h"
 #include <ctype.h>
