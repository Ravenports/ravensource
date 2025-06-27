--- src/gallium/drivers/llvmpipe/lp_scene.c.orig	2025-06-18 17:45:40 UTC
+++ src/gallium/drivers/llvmpipe/lp_scene.c
@@ -25,6 +25,10 @@
  *
  **************************************************************************/
 
+#ifdef __NetBSD__
+#define _OPENBSD_SOURCE
+#include <stdlib.h> /* for reallocarray */
+#endif
 #include "util/u_framebuffer.h"
 #include "util/u_math.h"
 #include "util/u_memory.h"
