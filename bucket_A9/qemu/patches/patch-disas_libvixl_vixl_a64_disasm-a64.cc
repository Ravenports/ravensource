--- disas/libvixl/vixl/a64/disasm-a64.cc.orig	2019-12-12 18:20:47 UTC
+++ disas/libvixl/vixl/a64/disasm-a64.cc
@@ -2693,7 +2693,7 @@ void Disassembler::AppendPCRelativeOffse
   if (offset < 0) {
     abs_offset = -abs_offset;
   }
-  AppendToOutput("#%c0x%" PRIx64, sign, abs_offset);
+  AppendToOutput("#%c0x%" PRIx64, sign, offset < 0 ? -offset : offset);
 }
 
 
