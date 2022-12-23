--- libpkgconf/bsdstubs.c.orig	2022-08-08 00:58:54 UTC
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
