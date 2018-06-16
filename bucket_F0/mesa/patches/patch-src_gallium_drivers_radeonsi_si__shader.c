--- src/gallium/drivers/radeonsi/si_shader.c.orig	2018-06-15 20:37:48 UTC
+++ src/gallium/drivers/radeonsi/si_shader.c
@@ -22,6 +22,10 @@
  * USE OR OTHER DEALINGS IN THE SOFTWARE.
  */
 
+#ifdef __sun__
+#include <alloca.h> /* for alloca */
+#endif
+
 #include "gallivm/lp_bld_const.h"
 #include "gallivm/lp_bld_gather.h"
 #include "gallivm/lp_bld_intr.h"
