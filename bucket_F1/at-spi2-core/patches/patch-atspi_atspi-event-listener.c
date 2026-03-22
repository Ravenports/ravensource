--- atspi/atspi-event-listener.c.orig	2026-01-03 13:59:10 UTC
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
