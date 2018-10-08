--- src/unix/fs.c.orig	2018-10-08 16:52:30 UTC
+++ src/unix/fs.c
@@ -216,7 +216,15 @@ static ssize_t uv__fs_futime(uv_fs_t* re
 
 
 static ssize_t uv__fs_mkdtemp(uv_fs_t* req) {
+#ifdef __sun__
+  char *tmplt;
+  tmplt = mktemp((char*) req->path);
+  if (tmplt == NULL)
+	return (-1);
+  return (mkdir (tmplt, 0700));
+#else
   return mkdtemp((char*) req->path) ? 0 : -1;
+#endif
 }
 
 
