--- absl/debugging/internal/vdso_support.cc.orig	2025-08-14 19:54:55 UTC
+++ absl/debugging/internal/vdso_support.cc
@@ -55,7 +55,7 @@
 using Elf32_auxv_t = Aux32Info;
 using Elf64_auxv_t = Aux64Info;
 #endif
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #if defined(__ELF_WORD_SIZE) && __ELF_WORD_SIZE == 64
 using Elf64_auxv_t = Elf64_Auxinfo;
 #endif
