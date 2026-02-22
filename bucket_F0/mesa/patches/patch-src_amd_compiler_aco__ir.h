--- src/amd/compiler/aco_ir.h.orig	2026-02-19 18:55:18 UTC
+++ src/amd/compiler/aco_ir.h
@@ -25,6 +25,10 @@
 #include <memory>
 #include <vector>
 
+#if defined(__sun__)
+#include <alloca.h>
+#endif
+
 typedef struct nir_shader nir_shader;
 
 namespace aco {
