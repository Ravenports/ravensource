--- gtk/updateiconcache.c.orig	2017-08-11 19:47:18 UTC
+++ gtk/updateiconcache.c
@@ -1550,7 +1550,7 @@ opentmp:
   if (!validate_file (tmp_cache_path))
     {
       g_printerr (_("The generated cache was invalid.\n"));
-      /*g_unlink (tmp_cache_path);*/
+      g_unlink (tmp_cache_path);
       exit (1);
     }
 
