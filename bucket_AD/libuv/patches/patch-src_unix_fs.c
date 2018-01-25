--- src/unix/fs.c.orig	2018-01-19 20:17:23 UTC
+++ src/unix/fs.c
@@ -259,7 +259,15 @@ skip:
 
 
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
 
 
