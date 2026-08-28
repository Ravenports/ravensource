--- src/amd/llvm/ac_llvm_build.h.orig	2026-08-05 21:14:26 UTC
+++ src/amd/llvm/ac_llvm_build.h
@@ -15,6 +15,10 @@
 
 #include <stdbool.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
