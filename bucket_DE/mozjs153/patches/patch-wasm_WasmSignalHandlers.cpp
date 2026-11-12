--- wasm/WasmSignalHandlers.cpp.orig	2026-11-03 18:46:58 UTC
+++ wasm/WasmSignalHandlers.cpp
@@ -36,6 +36,12 @@
 #  include <signal.h>
 #endif
 
+#if defined(__sun)
+#  define REG_RIP 14 // Index for RIP in gregs[]
+#  define REG_RBP 10 // Index for RBP in gregs[]
+#  define REG_RSP 15 // Index for RSP in gregs[]
+#endif
+
 using namespace js;
 using namespace js::wasm;
 
