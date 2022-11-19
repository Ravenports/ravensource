--- src/amd/llvm/ac_llvm_build.h.orig	2022-11-16 23:02:11 UTC
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
