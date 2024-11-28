--- src/amd/llvm/ac_llvm_build.h.orig	2024-11-13 15:28:52 UTC
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
