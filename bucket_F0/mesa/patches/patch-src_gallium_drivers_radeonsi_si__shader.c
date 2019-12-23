--- src/gallium/drivers/radeonsi/si_shader.c.orig	2019-12-18 18:36:00 UTC
+++ src/gallium/drivers/radeonsi/si_shader.c
@@ -24,6 +24,10 @@
 
 #include <llvm/Config/llvm-config.h>
 
+#ifdef __sun__
+#include <alloca.h> /* for alloca */
+#endif
+
 #include "util/u_memory.h"
 #include "util/u_string.h"
 #include "tgsi/tgsi_build.h"
