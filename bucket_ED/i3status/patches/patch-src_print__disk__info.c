--- src/print_disk_info.c.orig	2024-08-19 16:28:44 UTC
+++ src/print_disk_info.c
@@ -135,7 +135,7 @@ void print_disk_info(disk_info_ctx_t *ct
 #if defined(__DragonFly__) || defined(__APPLE__)
     struct statfs buf;
 
-    if (statfs(path, &buf) == -1)
+    if (statfs(ctx->path, &buf) == -1)
         return;
 
     mounted = true;
