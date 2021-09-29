--- src/amd/llvm/ac_llvm_build.h.orig	2021-09-21 16:54:05 UTC
+++ src/amd/llvm/ac_llvm_build.h
@@ -35,6 +35,10 @@
 
 #include <stdbool.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
