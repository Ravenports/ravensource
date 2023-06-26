--- src/util.c.orig	2023-06-19 20:39:23 UTC
+++ src/util.c
@@ -197,15 +197,22 @@ gboolean util_file_append(const char *fi
 {
     va_list args;
     FILE *f;
+    struct flock lock;
+
+    lock.l_whence = SEEK_SET;
+    lock.l_start = 0;
+    lock.l_len = 0;
 
     if (file && (f = fopen(file, "a+"))) {
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
@@ -225,13 +232,19 @@ gboolean util_file_prepend(const char *f
     va_list args;
     char *content;
     FILE *f;
+    struct flock lock;
+
     if (!file) {
         return FALSE;
     }
 
+    lock.l_whence = SEEK_SET;
+    lock.l_start = 0;
+    lock.l_len = 0;
     content = util_get_file_contents(file, NULL);
     if ((f = fopen(file, "w"))) {
-        flock(fileno(f), LOCK_EX);
+        lock.l_type = F_WRLCK;
+        fcntl(fileno(f), F_SETLKW, &lock);
 
         va_start(args, format);
         /* write new content to the file */
@@ -241,7 +254,8 @@ gboolean util_file_prepend(const char *f
         /* append previous file content */
         fputs(content, f);
 
-        flock(fileno(f), LOCK_UN);
+        lock.l_type = F_UNLCK;
+        fcntl(fileno(f), F_SETLK, &lock);
         fclose(f);
 
         res = TRUE;
