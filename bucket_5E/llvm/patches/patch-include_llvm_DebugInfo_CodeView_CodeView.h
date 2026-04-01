--- include/llvm/DebugInfo/CodeView/CodeView.h.orig	2026-03-23 18:46:22 UTC
+++ include/llvm/DebugInfo/CodeView/CodeView.h
@@ -16,6 +16,25 @@
 #include "llvm/Support/Compiler.h"
 #include <cinttypes>
 
+#ifdef __sun
+#undef ERR
+#undef EAX
+#undef ECX
+#undef EDX
+#undef EBX
+#undef ESP
+#undef EBP
+#undef ESI
+#undef EDI
+#undef EIP
+#undef CS
+#undef DS
+#undef ES
+#undef FS
+#undef GS
+#undef SS
+#endif
+
 #include "llvm/ADT/STLForwardCompat.h"
 #include "llvm/Support/Endian.h"
 
