--- include/llvm/DebugInfo/CodeView/CodeView.h.orig	2024-06-15 17:21:32 UTC
+++ include/llvm/DebugInfo/CodeView/CodeView.h
@@ -16,6 +16,25 @@
 #include <cinttypes>
 #include <type_traits>
 
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
 
