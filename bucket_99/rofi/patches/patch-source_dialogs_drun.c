--- source/dialogs/drun.c.orig	2021-08-29 09:11:37 UTC
+++ source/dialogs/drun.c
@@ -728,11 +728,20 @@ static void walk_dir(DRunModePrivateData
     if (file->d_name[0] == '.') {
       continue;
     }
+#ifdef __sun__
+    stat(file->d_name, &st);
+    switch (st.st_mode) {
+    case S_IFLNK:
+    case S_IFREG:
+    case S_IFDIR:
+    case 0:
+#else
     switch (file->d_type) {
     case DT_LNK:
     case DT_REG:
     case DT_DIR:
     case DT_UNKNOWN:
+#endif
       filename = g_build_filename(dirname, file->d_name, NULL);
       break;
     default:
@@ -741,6 +750,21 @@ static void walk_dir(DRunModePrivateData
 
     // On a link, or if FS does not support providing this information
     // Fallback to stat method.
+#ifdef __sun__
+    switch (st.st_mode) {
+    case S_IFREG:
+        // Skip files not ending on .desktop.
+        if ( g_str_has_suffix ( file->d_name, ".desktop" ) ) {
+            read_desktop_file ( pd, root, filename, file->d_name, DRUN_GROUP_NAME );
+        }
+        break;
+    case S_IFDIR:
+        walk_dir ( pd, root, filename );
+        break;
+    default:
+        break;
+    }
+#else
     if (file->d_type == DT_LNK || file->d_type == DT_UNKNOWN) {
       file->d_type = DT_UNKNOWN;
       if (stat(filename, &st) == 0) {
@@ -765,6 +789,7 @@ static void walk_dir(DRunModePrivateData
     default:
       break;
     }
+#endif
     g_free(filename);
   }
   closedir(dir);
