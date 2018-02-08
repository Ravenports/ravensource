--- src/gallium/drivers/radeonsi/si_shader.c.orig	2018-01-18 21:30:28 UTC
+++ src/gallium/drivers/radeonsi/si_shader.c
@@ -26,6 +26,10 @@
  *      Christian König <christian.koenig@amd.com>
  */
 
+#ifdef __sun__
+#include <alloca.h> /* for alloca */
+#endif
+
 #include "gallivm/lp_bld_const.h"
 #include "gallivm/lp_bld_gather.h"
 #include "gallivm/lp_bld_intr.h"
