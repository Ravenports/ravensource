--- gtk/updateiconcache.c.orig	2025-01-25 13:25:12 UTC
+++ gtk/updateiconcache.c
@@ -1562,7 +1562,7 @@ opentmp:
   if (!validate_file (tmp_cache_path))
     {
       g_printerr (_("The generated cache was invalid.\n"));
-      /*g_unlink (tmp_cache_path);*/
+      g_unlink (tmp_cache_path);
       exit (1);
     }
 
