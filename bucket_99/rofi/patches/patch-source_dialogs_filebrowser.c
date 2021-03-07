--- source/dialogs/filebrowser.c.orig	2020-11-22 21:02:43 UTC
+++ source/dialogs/filebrowser.c
@@ -107,6 +107,9 @@ static gint compare ( gconstpointer a, g
 
 static void get_file_browser (  Mode *sw )
 {
+#ifdef __sun__
+    struct stat st;
+#endif
     FileBrowserModePrivateData *pd = (FileBrowserModePrivateData *) mode_get_private_data ( sw );
     /**
      * Get the entries to display.
@@ -132,6 +135,19 @@ static void get_file_browser (  Mode *sw
                 continue;
             }
 
+#ifdef __sun__
+            stat (rd->d_name, &st);
+            switch (st.st_mode) 
+            {
+            case S_IFBLK:
+            case S_IFCHR:
+            case S_IFIFO:
+            case S_IFSOCK:
+            default:
+                break;
+            case S_IFREG:
+            case S_IFDIR:
+#else
             switch ( rd->d_type )
             {
             case DT_BLK:
@@ -143,16 +159,27 @@ static void get_file_browser (  Mode *sw
                 break;
             case DT_REG:
             case DT_DIR:
+#endif
                 pd->array = g_realloc ( pd->array, ( pd->array_length + 1 ) * sizeof ( FBFile ) );
                 // Rofi expects utf-8, so lets convert the filename.
                 pd->array[pd->array_length].name           = g_filename_to_utf8 ( rd->d_name, -1, NULL, NULL, NULL );
                 pd->array[pd->array_length].path           = g_build_filename ( cdir, rd->d_name, NULL );
-                pd->array[pd->array_length].type           = ( rd->d_type == DT_DIR ) ? DIRECTORY : RFILE;
+                pd->array[pd->array_length].type           =
+#ifdef __sun__
+                  ( st.st_mode == S_IFDIR )
+#else
+                  ( rd->d_type == DT_DIR )
+#endif
+                  ? DIRECTORY : RFILE;
                 pd->array[pd->array_length].icon_fetch_uid = 0;
                 pd->array[pd->array_length].link           = FALSE;
                 pd->array_length++;
                 break;
+#ifdef __sun__
+            case S_IFLNK:
+#else
             case DT_LNK:
+#endif
                 pd->array = g_realloc ( pd->array, ( pd->array_length + 1 ) * sizeof ( FBFile ) );
                 // Rofi expects utf-8, so lets convert the filename.
                 pd->array[pd->array_length].name           = g_filename_to_utf8 ( rd->d_name, -1, NULL, NULL, NULL );
