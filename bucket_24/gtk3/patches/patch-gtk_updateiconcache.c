--- gtk/updateiconcache.c.orig	2021-03-22 01:46:05 UTC
+++ gtk/updateiconcache.c
@@ -1557,7 +1557,7 @@ opentmp:
   if (!validate_file (tmp_cache_path))
     {
       g_printerr (_("The generated cache was invalid.\n"));
-      /*g_unlink (tmp_cache_path);*/
+      g_unlink (tmp_cache_path);
       exit (1);
     }
 
