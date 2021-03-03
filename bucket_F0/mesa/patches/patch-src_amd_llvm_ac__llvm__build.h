--- src/amd/llvm/ac_llvm_build.h.orig	2021-01-29 18:33:19 UTC
+++ src/amd/llvm/ac_llvm_build.h
@@ -34,6 +34,10 @@
 
 #include <stdbool.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
