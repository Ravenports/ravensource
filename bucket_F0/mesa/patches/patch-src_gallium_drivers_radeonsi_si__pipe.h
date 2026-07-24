--- src/gallium/drivers/radeonsi/si_pipe.h.orig	2026-05-19 14:27:16 UTC
+++ src/gallium/drivers/radeonsi/si_pipe.h
@@ -29,6 +29,10 @@
 #endif
 #include "u_stub.h"
 
+#if defined(__sun__)
+#include <alloca.h>
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
