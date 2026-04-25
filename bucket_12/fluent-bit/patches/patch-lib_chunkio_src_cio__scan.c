--- lib/chunkio/src/cio_scan.c.orig	2026-04-14 17:27:00 UTC
+++ lib/chunkio/src/cio_scan.c
@@ -21,6 +21,9 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
+#if defined __sun__
+#include <sys/stat.h>
+#endif
 
 #include <chunkio/chunkio_compat.h>
 #include <chunkio/chunkio.h>
@@ -47,6 +50,10 @@ static int cio_scan_stream_files(struct
     char *path;
     DIR *dir;
     struct dirent *ent;
+#if defined __sun__
+    char full_path[1024];
+    struct stat stx;
+#endif
 
     len = strlen(ctx->options.root_path) + strlen(st->name) + 2;
     path = malloc(len);
@@ -82,7 +89,12 @@ static int cio_scan_stream_files(struct
         }
 
         /* Look just for directories */
+#if defined __sun__
+        snprintf(full_path, sizeof(full_path), "%s/%s", path, ent->d_name);
+        if (stat(full_path, &stx) == -1 || !S_ISREG(stx.st_mode)) {
+#else
         if (ent->d_type != DT_REG) {
+#endif
             continue;
         }
 
@@ -129,6 +141,10 @@ int cio_scan_streams(struct cio_ctx *ctx
     DIR *dir;
     struct dirent *ent;
     struct cio_stream *st;
+#if defined __sun__
+    char full_path[1024];
+    struct stat stx;
+#endif
 
     dir = opendir(ctx->options.root_path);
     if (!dir) {
@@ -145,7 +161,12 @@ int cio_scan_streams(struct cio_ctx *ctx
         }
 
         /* Look just for directories */
+#if defined __sun__
+	snprintf(full_path, sizeof(full_path), "%s/%s", ctx->options.root_path, ent->d_name);
+	if (stat(full_path, &stx) == -1 || !S_ISDIR(stx.st_mode)) {
+#else
         if (ent->d_type != DT_DIR) {
+#endif
             continue;
         }
 
