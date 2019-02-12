--- src/gallium/drivers/radeonsi/si_shader.c.orig	2018-12-13 14:02:20 UTC
+++ src/gallium/drivers/radeonsi/si_shader.c
@@ -22,6 +22,10 @@
  * USE OR OTHER DEALINGS IN THE SOFTWARE.
  */
 
+#ifdef __sun__
+#include <alloca.h> /* for alloca */
+#endif
+
 #include "util/u_memory.h"
 #include "util/u_string.h"
 #include "tgsi/tgsi_build.h"
