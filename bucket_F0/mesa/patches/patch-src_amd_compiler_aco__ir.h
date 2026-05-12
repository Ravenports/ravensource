--- src/amd/compiler/aco_ir.h.orig	2026-04-29 20:19:00 UTC
+++ src/amd/compiler/aco_ir.h
@@ -25,6 +25,10 @@
 #include <memory>
 #include <vector>
 
+#if defined(__sun__)
+#include <alloca.h>
+#endif
+
 typedef struct nir_shader nir_shader;
 typedef struct nir_parameter nir_parameter;
 
