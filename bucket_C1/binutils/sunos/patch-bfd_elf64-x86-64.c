--- bfd/elf64-x86-64.c.orig	2017-09-19 07:11:58 UTC
+++ bfd/elf64-x86-64.c
@@ -531,8 +531,8 @@ elf_x86_64_write_core_note (bfd *abfd, c
 /* The name of the dynamic interpreter.	 This is put in the .interp
    section.  */
 
-#define ELF64_DYNAMIC_INTERPRETER "/lib/ld64.so.1"
-#define ELF32_DYNAMIC_INTERPRETER "/lib/ldx32.so.1"
+#define ELF64_DYNAMIC_INTERPRETER "/lib/amd64/ld.so.1"
+#define ELF32_DYNAMIC_INTERPRETER "/lib/ld.so.1"
 
 /* If ELIMINATE_COPY_RELOCS is non-zero, the linker will try to avoid
    copying dynamic variables from a shared lib into an app's dynbss
