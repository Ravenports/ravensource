--- disas/libvixl/vixl/a64/disasm-a64.cc.orig	2020-08-11 19:17:14 UTC
+++ disas/libvixl/vixl/a64/disasm-a64.cc
@@ -2693,7 +2693,7 @@ void Disassembler::AppendPCRelativeOffse
   if (offset < 0) {
     abs_offset = -abs_offset;
   }
-  AppendToOutput("#%c0x%" PRIx64, sign, abs_offset);
+  AppendToOutput("#%c0x%" PRIx64, sign, offset < 0 ? -offset : offset);
 }
 
 
