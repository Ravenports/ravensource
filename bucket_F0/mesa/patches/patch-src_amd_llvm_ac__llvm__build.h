--- src/amd/llvm/ac_llvm_build.h.orig	2026-08-20 08:57:40 UTC
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
