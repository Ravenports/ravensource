--- wasm/WasmSignalHandlers.cpp.orig	2026-03-17 09:42:15 UTC
+++ wasm/WasmSignalHandlers.cpp
@@ -38,6 +38,12 @@
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
 
