--- gtk/updateiconcache.c.orig	2019-11-27 15:23:51 UTC
+++ gtk/updateiconcache.c
@@ -1548,7 +1548,7 @@ opentmp:
   if (!validate_file (tmp_cache_path))
     {
       g_printerr (_("The generated cache was invalid.\n"));
-      /*g_unlink (tmp_cache_path);*/
+      g_unlink (tmp_cache_path);
       exit (1);
     }
 
