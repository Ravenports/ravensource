--- src/gallium/winsys/virgl/vtest/virgl_vtest_socket.c.orig	2026-04-15 14:20:41 UTC
+++ src/gallium/winsys/virgl/vtest/virgl_vtest_socket.c
@@ -21,6 +21,7 @@
  * USE OR OTHER DEALINGS IN THE SOFTWARE.
  */
 
+#define _XPG4_2
 #include <sys/socket.h>
 #include <errno.h>
 #include <stdio.h>
