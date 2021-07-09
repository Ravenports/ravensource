--- gtk/updateiconcache.c.orig	2021-06-15 20:58:25 UTC
+++ gtk/updateiconcache.c
@@ -1556,7 +1556,7 @@ opentmp:
   if (!validate_file (tmp_cache_path))
     {
       g_printerr (_("The generated cache was invalid.\n"));
-      /*g_unlink (tmp_cache_path);*/
+      g_unlink (tmp_cache_path);
       exit (1);
     }
 
