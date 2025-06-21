--- libpkgconf/bsdstubs.c.orig	2025-06-19 04:56:01 UTC
+++ libpkgconf/bsdstubs.c
@@ -17,6 +17,9 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#ifdef __NetBSD__
+#define _OPENBSD_SOURCE
+#endif
 #include <stdlib.h>
 #include <sys/types.h>
 #include <string.h>
