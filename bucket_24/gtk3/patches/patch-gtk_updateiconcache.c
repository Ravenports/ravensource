--- gtk/updateiconcache.c.orig	2026-03-23 02:24:49 UTC
+++ gtk/updateiconcache.c
@@ -1566,7 +1566,7 @@ opentmp:
   if (!validate_file (tmp_cache_path))
     {
       g_printerr (_("The generated cache was invalid.\n"));
-      /*g_unlink (tmp_cache_path);*/
+      g_unlink (tmp_cache_path);
       exit (1);
     }
 
