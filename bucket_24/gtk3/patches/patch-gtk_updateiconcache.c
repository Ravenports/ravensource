--- gtk/updateiconcache.c.orig	2025-09-29 23:41:38 UTC
+++ gtk/updateiconcache.c
@@ -1566,7 +1566,7 @@ opentmp:
   if (!validate_file (tmp_cache_path))
     {
       g_printerr (_("The generated cache was invalid.\n"));
-      /*g_unlink (tmp_cache_path);*/
+      g_unlink (tmp_cache_path);
       exit (1);
     }
 
