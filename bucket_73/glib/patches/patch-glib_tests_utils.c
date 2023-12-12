--- glib/tests/utils.c.orig	2023-12-06 18:03:55 UTC
+++ glib/tests/utils.c
@@ -850,7 +850,7 @@ test_xdg_dirs (void)
 
   xdg = (gchar *)g_getenv ("XDG_CONFIG_DIRS");
   if (!xdg)
-    xdg = "/etc/xdg";
+    xdg = "/usr/local/etc/xdg:/etc/xdg";
 
   dirs = g_get_system_config_dirs ();
 
