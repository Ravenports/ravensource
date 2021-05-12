--- storage/myisam/mi_dynrec.cc.orig	2021-04-23 15:06:40 UTC
+++ storage/myisam/mi_dynrec.cc
@@ -92,6 +92,9 @@ bool mi_dynmap_file(MI_INFO *info, my_of
       mapping. When swap space is not reserved one might get SIGSEGV
       upon a write if no physical memory is available.
   */
+#ifndef MAP_NORESERVE
+#define MAP_NORESERVE	0
+#endif
   info->s->file_map = (uchar *)my_mmap(
       nullptr, (size_t)size,
       info->s->mode == O_RDONLY ? PROT_READ : PROT_READ | PROT_WRITE,
