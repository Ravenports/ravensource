Apprently g_file_query_exists is failing with latest glib20.
Ignore attempt to create existing directory to allow colord to build.

--- lib/colord/cd-icc.c.orig	2024-01-22 12:41:38 UTC
+++ lib/colord/cd-icc.c
@@ -1501,7 +1501,9 @@ cd_icc_save_file_mkdir_parents (GFile *f
 	if (g_file_query_exists (parent_dir, NULL))
 		return TRUE;
 	if (!g_file_make_directory_with_parents (parent_dir, NULL, error))
-		return FALSE;
+	{
+		g_print("failed to mkdir %s\n", g_file_get_path (parent_dir));
+	}
 	return TRUE;
 }
 
