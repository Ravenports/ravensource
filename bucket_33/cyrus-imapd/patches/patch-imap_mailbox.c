--- imap/mailbox.c.orig	2026-03-29 22:54:00 UTC
+++ imap/mailbox.c
@@ -6046,6 +6046,10 @@ static void mailbox_delete_files(const c
     struct dirent *f;
     char buf[MAX_MAILBOX_PATH+1];
     char *tail;
+#if defined(__sun)
+    struct stat st;
+    char mypath[1024];
+#endif
 
     strlcpy(buf, path, sizeof(buf));
 
@@ -6062,7 +6066,12 @@ static void mailbox_delete_files(const c
     dirp = opendir(path);
     if (dirp) {
         while ((f = readdir(dirp))!=NULL) {
+#if defined(__sun)
+            snprintf(mypath, sizeof(mypath), "%s/%s", path, f->d_name);
+            if (stat(mypath, &st) == 0 && S_ISDIR(st.st_mode)) {
+#else
             if (f->d_type == DT_DIR) {
+#endif
                 /* xunlink() will fail on a directory and create syslog noise.
                    We rmdir() later in mailbox_delete_cleanup() anyways */
                 continue;
