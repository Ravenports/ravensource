--- src/gallium/drivers/radeonsi/si_shader.c.orig	2020-04-29 22:48:24 UTC
+++ src/gallium/drivers/radeonsi/si_shader.c
@@ -22,6 +22,10 @@
  * USE OR OTHER DEALINGS IN THE SOFTWARE.
  */
 
+#ifdef __sun__
+#include <alloca.h> /* for alloca */
+#endif
+
 #include "util/u_memory.h"
 #include "tgsi/tgsi_strings.h"
 #include "tgsi/tgsi_from_mesa.h"
