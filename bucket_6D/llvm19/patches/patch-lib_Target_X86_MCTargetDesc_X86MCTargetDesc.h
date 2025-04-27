--- lib/Target/X86/MCTargetDesc/X86MCTargetDesc.h.orig	2025-01-14 09:41:02 UTC
+++ lib/Target/X86/MCTargetDesc/X86MCTargetDesc.h
@@ -17,6 +17,24 @@
 #include <memory>
 #include <string>
 
+#ifdef __sun
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
 namespace llvm {
 class formatted_raw_ostream;
 class MCAsmBackend;
