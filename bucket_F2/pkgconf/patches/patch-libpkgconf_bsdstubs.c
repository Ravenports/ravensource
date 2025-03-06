--- libpkgconf/bsdstubs.c.orig	2024-08-05 19:52:16 UTC
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
