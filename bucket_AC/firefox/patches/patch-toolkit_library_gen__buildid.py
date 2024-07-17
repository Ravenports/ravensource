--- toolkit/library/gen_buildid.py.orig	2024-07-04 17:04:30 UTC
+++ toolkit/library/gen_buildid.py
@@ -78,7 +78,7 @@ def write_file(output, maybe_buildid):
 #endif
 
 struct note {{
-    Elf32_Nhdr header; // Elf32 or Elf64 doesn't matter, they're the same size
+    Elf64_Nhdr header; // Elf32 or Elf64 doesn't matter, they're the same size
     char name[(sizeof(note_name) + 3) / 4 * 4];
     char desc[(sizeof(note_desc) + 3) / 4 * 4];
 }};
