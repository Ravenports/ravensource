--- src/history.c.orig	2023-06-19 20:39:23 UTC
+++ src/history.c
@@ -259,8 +259,14 @@ static GList *load(FileStorage *s)
 static void write_to_file(GList *list, const char *file)
 {
     FILE *f;
+    struct flock lock;
+
+    lock.l_whence = SEEK_SET;
+    lock.l_start = 0;
+    lock.l_len = 0;
     if ((f = fopen(file, "w"))) {
-        flock(fileno(f), LOCK_EX);
+        lock.l_type = F_WRLCK;
+        fcntl(fileno(f), F_SETLKW, &lock);
 
         /* overwrite the history file with new unique history items */
         for (GList *link = list; link; link = link->next) {
@@ -272,7 +278,8 @@ static void write_to_file(GList *list, c
             }
         }
 
-        flock(fileno(f), LOCK_UN);
+        lock.l_type = F_UNLCK;
+        fcntl(fileno(f), F_SETLK, &lock);
         fclose(f);
     }
 }
