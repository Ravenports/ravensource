# Elf_ doesn't exist, use Elf32_ or Elf64_
#
--- src/util/build_id.c.orig	2026-03-18 15:54:10 UTC
+++ src/util/build_id.c
@@ -43,7 +43,11 @@ struct build_id_note {
 #endif
 
 #ifndef ElfW
-#define ElfW(type) Elf_##type
+#ifdef __LP64__
+#define ElfW(type) Elf64_##type
+#else
+#define ElfW(type) Elf32_##type
+#endif
 #endif
 
 struct build_id_note {
