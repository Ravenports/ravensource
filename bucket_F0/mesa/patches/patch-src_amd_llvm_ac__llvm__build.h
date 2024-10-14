--- src/amd/llvm/ac_llvm_build.h.orig	2024-10-03 15:38:59 UTC
+++ src/amd/llvm/ac_llvm_build.h
@@ -16,6 +16,10 @@
 
 #include <stdbool.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
