--- storage/myisam/mi_dynrec.cc.orig	2025-07-09 08:45:01 UTC
+++ storage/myisam/mi_dynrec.cc
@@ -93,6 +93,9 @@ bool mi_dynmap_file(MI_INFO *info, my_of
       mapping. When swap space is not reserved one might get SIGSEGV
       upon a write if no physical memory is available.
   */
+#ifndef MAP_NORESERVE
+#define MAP_NORESERVE	0
+#endif
   info->s->file_map = (uchar *)my_mmap(
       nullptr, (size_t)size,
       info->s->mode == O_RDONLY ? PROT_READ : PROT_READ | PROT_WRITE,
