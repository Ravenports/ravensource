--- source/dialogs/filebrowser.c.orig	2021-08-29 09:11:37 UTC
+++ source/dialogs/filebrowser.c
@@ -200,6 +200,9 @@ static void set_time(FBFile *file) {
 }
 
 static void get_file_browser(Mode *sw) {
+#ifdef __sun__
+  struct stat st;
+#endif
   FileBrowserModePrivateData *pd =
       (FileBrowserModePrivateData *)mode_get_private_data(sw);
   /**
@@ -228,6 +231,18 @@ static void get_file_browser(Mode *sw) {
         continue;
       }
 
+#ifdef __sun__
+      stat (rd->d_name, &st);
+      switch (st.st_mode) {
+      case S_IFBLK:
+      case S_IFCHR:
+      case S_IFIFO:
+      case S_IFSOCK:
+      default:
+          break;
+      case S_IFREG:
+      case S_IFDIR:
+#else
       switch (rd->d_type) {
       case DT_BLK:
       case DT_CHR:
@@ -238,6 +253,7 @@ static void get_file_browser(Mode *sw) {
         break;
       case DT_REG:
       case DT_DIR:
+#endif
         pd->array =
             g_realloc(pd->array, (pd->array_length + 1) * sizeof(FBFile));
         // Rofi expects utf-8, so lets convert the filename.
@@ -246,7 +262,11 @@ static void get_file_browser(Mode *sw) {
         pd->array[pd->array_length].path =
             g_build_filename(cdir, rd->d_name, NULL);
         pd->array[pd->array_length].type =
+#ifdef __sun__
+            (st.st_mode == S_IFDIR) ? DIRECTORY : RFILE;
+#else
             (rd->d_type == DT_DIR) ? DIRECTORY : RFILE;
+#endif
         pd->array[pd->array_length].icon_fetch_uid = 0;
         pd->array[pd->array_length].link = FALSE;
 
@@ -256,7 +276,11 @@ static void get_file_browser(Mode *sw) {
 
         pd->array_length++;
         break;
+#ifdef __sun__
+      case S_IFLNK:
+#else
       case DT_LNK:
+#endif
         pd->array =
             g_realloc(pd->array, (pd->array_length + 1) * sizeof(FBFile));
         // Rofi expects utf-8, so lets convert the filename.
