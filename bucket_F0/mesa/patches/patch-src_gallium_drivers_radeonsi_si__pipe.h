--- src/gallium/drivers/radeonsi/si_pipe.h.orig	2026-08-05 21:14:26 UTC
+++ src/gallium/drivers/radeonsi/si_pipe.h
@@ -25,6 +25,10 @@
 #include "ac_spm.h"
 #include "si_perfetto.h"
 
+#if defined(__sun__)
+#include <alloca.h>
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
