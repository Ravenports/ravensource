--- gtk/updateiconcache.c.orig	2020-12-18 05:50:58 UTC
+++ gtk/updateiconcache.c
@@ -1554,7 +1554,7 @@ opentmp:
   if (!validate_file (tmp_cache_path))
     {
       g_printerr (_("The generated cache was invalid.\n"));
-      /*g_unlink (tmp_cache_path);*/
+      g_unlink (tmp_cache_path);
       exit (1);
     }
 
