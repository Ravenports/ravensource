# Elf_ doesn't exist, use Elf32_ or Elf64_
#
--- src/util/build_id.c.orig	2025-01-22 18:12:23 UTC
+++ src/util/build_id.c
@@ -35,7 +35,11 @@
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
