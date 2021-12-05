--- source/dialogs/filebrowser.c.orig	2021-10-15 23:19:17 UTC
+++ source/dialogs/filebrowser.c
@@ -216,6 +216,9 @@ inline static void fb_resize_array(FileB
 }
 
 static void get_file_browser(Mode *sw) {
+#ifdef __sun__
+  struct stat st;
+#endif
   FileBrowserModePrivateData *pd =
       (FileBrowserModePrivateData *)mode_get_private_data(sw);
   /**
@@ -243,6 +246,18 @@ static void get_file_browser(Mode *sw) {
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
@@ -253,6 +268,7 @@ static void get_file_browser(Mode *sw) {
         break;
       case DT_REG:
       case DT_DIR:
+#endif
         fb_resize_array(pd);
         // Rofi expects utf-8, so lets convert the filename.
         pd->array[pd->array_length].name =
@@ -263,7 +279,11 @@ static void get_file_browser(Mode *sw) {
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
 
@@ -273,7 +293,11 @@ static void get_file_browser(Mode *sw) {
 
         pd->array_length++;
         break;
+#ifdef __sun__
+      case S_IFLNK:
+#else
       case DT_LNK:
+#endif
         fb_resize_array(pd);
         // Rofi expects utf-8, so lets convert the filename.
         pd->array[pd->array_length].name =
