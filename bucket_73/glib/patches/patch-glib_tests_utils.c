--- glib/tests/utils.c.orig	2021-09-17 10:17:56 UTC
+++ glib/tests/utils.c
@@ -511,7 +511,7 @@ test_xdg_dirs (void)
 
   xdg = (gchar *)g_getenv ("XDG_CONFIG_DIRS");
   if (!xdg)
-    xdg = "/etc/xdg";
+    xdg = "/usr/local/etc/xdg:/etc/xdg";
 
   dirs = g_get_system_config_dirs ();
 
