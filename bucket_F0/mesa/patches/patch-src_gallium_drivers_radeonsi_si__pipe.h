--- src/gallium/drivers/radeonsi/si_pipe.h.orig	2026-02-19 18:55:18 UTC
+++ src/gallium/drivers/radeonsi/si_pipe.h
@@ -23,6 +23,10 @@
 #include "ac_spm.h"
 #include "si_perfetto.h"
 
+#if defined(__sun__)
+#include <alloca.h>
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
