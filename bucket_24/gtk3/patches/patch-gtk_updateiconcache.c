--- gtk/updateiconcache.c.orig	2019-04-10 19:30:43 UTC
+++ gtk/updateiconcache.c
@@ -1548,7 +1548,7 @@ opentmp:
   if (!validate_file (tmp_cache_path))
     {
       g_printerr (_("The generated cache was invalid.\n"));
-      /*g_unlink (tmp_cache_path);*/
+      g_unlink (tmp_cache_path);
       exit (1);
     }
 
