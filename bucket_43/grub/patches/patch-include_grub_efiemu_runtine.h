--- include/grub/efiemu/runtime.h.orig	2018-10-07 17:22:59.152577000 +0200
+++ include/grub/efiemu/runtime.h	2018-10-07 17:28:09.182671000 +0200
@@ -29,7 +29,7 @@
 
 struct efi_variable
 {
-  grub_efi_guid_t guid;
+  grub_efi_packed_guid_t guid;
   grub_uint32_t namelen;
   grub_uint32_t size;
   grub_efi_uint32_t attributes;
