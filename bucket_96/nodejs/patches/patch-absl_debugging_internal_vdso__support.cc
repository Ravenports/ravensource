--- deps/v8/third_party/abseil-cpp/absl/debugging/internal/vdso_support.cc.orig	2024-12-10 10:44:43 UTC
+++ deps/v8/third_party/abseil-cpp/absl/debugging/internal/vdso_support.cc
@@ -54,7 +54,7 @@
 using Elf32_auxv_t = Aux32Info;
 using Elf64_auxv_t = Aux64Info;
 #endif
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #if defined(__ELF_WORD_SIZE) && __ELF_WORD_SIZE == 64
 using Elf64_auxv_t = Elf64_Auxinfo;
 #endif
