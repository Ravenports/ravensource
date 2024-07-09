$NetBSD: patch-libguile_loader.c,v 1.1 2022/03/08 00:09:30 wiz Exp $

Use correct mmap permissions for later PROT_WRITE mprotect.

--- libguile/loader.c.orig	2021-02-03 22:00:27 UTC
+++ libguile/loader.c
@@ -501,7 +501,7 @@ map_file_contents (int fd, size_t len, i
   char *data;
 
 #ifdef HAVE_SYS_MMAN_H
-  data = mmap (NULL, len, PROT_READ, MAP_PRIVATE, fd, 0);
+  data = mmap (NULL, len, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
   if (data == MAP_FAILED)
     SCM_SYSERROR;
   *is_read_only = 1;
