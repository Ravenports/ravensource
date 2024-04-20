--- lib/tsan/sanitizer_common/sanitizer_linux_libcdep.cpp.orig	2024-04-19 21:00:35 UTC
+++ lib/tsan/sanitizer_common/sanitizer_linux_libcdep.cpp
@@ -628,7 +628,7 @@ void GetThreadStackAndTls(bool main, upt
 
 #if !SANITIZER_FREEBSD
 typedef ElfW(Phdr) Elf_Phdr;
-#elif SANITIZER_WORDSIZE == 32 && __FreeBSD_version <= 902001  // v9.2
+#elif 0
 #define Elf_Phdr XElf32_Phdr
 #define dl_phdr_info xdl_phdr_info
 #define dl_iterate_phdr(c, b) xdl_iterate_phdr((c), (b))
