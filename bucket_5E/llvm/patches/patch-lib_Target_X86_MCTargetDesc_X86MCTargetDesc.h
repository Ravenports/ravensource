--- lib/Target/X86/MCTargetDesc/X86MCTargetDesc.h.orig	2024-05-18 14:14:07 UTC
+++ lib/Target/X86/MCTargetDesc/X86MCTargetDesc.h
@@ -16,6 +16,24 @@
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
