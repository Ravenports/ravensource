--- bfd/elfxx-x86.c.orig	2026-02-08 00:00:00 UTC
+++ bfd/elfxx-x86.c
@@ -26,8 +26,8 @@
    section.  */
 
 #define ELF32_DYNAMIC_INTERPRETER "/usr/lib/libc.so.1"
-#define ELF64_DYNAMIC_INTERPRETER "/lib/ld64.so.1"
-#define ELFX32_DYNAMIC_INTERPRETER "/lib/ldx32.so.1"
+#define ELF64_DYNAMIC_INTERPRETER "@ELF64_INTERPRETER@"
+#define ELFX32_DYNAMIC_INTERPRETER "@ELF32_INTERPRETER@"
 
 /* ??? This repeats *COM* id of zero.  sec->id is supposed to be unique,
    but current usage would allow all of _bfd_std_section to be zero.  */
