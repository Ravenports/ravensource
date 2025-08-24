--- kprop/kproplog.c.orig	2025-08-20 19:44:32 UTC
+++ kprop/kproplog.c
@@ -415,7 +415,7 @@ map_ulog(const char *filename, int *fd_o
         close(fd);
         return NULL;
     }
-    ulog = mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
+    ulog = (kdb_hlog_t *)mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
     if (ulog == MAP_FAILED) {
         close(fd);
         return NULL;
