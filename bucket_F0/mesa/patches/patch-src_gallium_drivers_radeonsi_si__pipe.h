--- src/gallium/drivers/radeonsi/si_pipe.h.orig	2026-04-15 14:20:41 UTC
+++ src/gallium/drivers/radeonsi/si_pipe.h
@@ -24,6 +24,10 @@
 #include "ac_spm.h"
 #include "si_perfetto.h"
 
+#if defined(__sun__)
+#include <alloca.h>
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
