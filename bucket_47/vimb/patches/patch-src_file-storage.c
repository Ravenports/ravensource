--- src/file-storage.c.orig	2023-06-19 20:39:23 UTC
+++ src/file-storage.c
@@ -23,6 +23,7 @@
 #include <glib/gstdio.h>
 
 #include "file-storage.h"
+#include <fcntl.h>
 
 struct filestorage {
     char        *file_path;
@@ -85,6 +86,11 @@ gboolean file_storage_append(FileStorage
 {
     FILE *f;
     va_list args;
+    struct flock lock;
+
+    lock.l_whence = SEEK_SET;
+    lock.l_start = 0;
+    lock.l_len = 0;
 
     g_assert(storage);
 
@@ -96,11 +102,13 @@ gboolean file_storage_append(FileStorage
         return TRUE;
     }
     if ((f = fopen(storage->file_path, "a+"))) {
-        flock(fileno(f), LOCK_EX);
+        lock.l_type = F_WRLCK;
+        fcntl(fileno(f), F_SETLKW, &lock);
         va_start(args, format);
         vfprintf(f, format, args);
         va_end(args);
-        flock(fileno(f), LOCK_UN);
+        lock.l_type = F_UNLCK;
+        fcntl(fileno(f), F_SETLK, &lock);
         fclose(f);
         return TRUE;
     }
