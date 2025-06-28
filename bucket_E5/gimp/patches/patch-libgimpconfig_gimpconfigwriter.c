--- libgimpconfig/gimpconfigwriter.c.orig	2025-05-17 22:51:03 UTC
+++ libgimpconfig/gimpconfigwriter.c
@@ -148,11 +148,8 @@ gimp_config_writer_new_from_file (GFile
   dir = g_file_get_parent (file);
   if (dir && ! g_file_query_exists (dir, NULL))
     {
-      if (! g_file_make_directory_with_parents (dir, NULL, error))
-        g_prefix_error (error,
-                        _("Could not create directory '%s' for '%s': "),
-                        gimp_file_get_utf8_name (dir),
-                        gimp_file_get_utf8_name (file));
+      if (! g_file_make_directory_with_parents (dir, NULL, NULL))
+        g_print("failed to mkdir %s (probably already exists)\n", g_file_get_path (dir));
     }
   g_object_unref (dir);
 
