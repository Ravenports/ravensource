--- glib/tests/utils.c.orig	2019-04-15 11:47:57 UTC
+++ glib/tests/utils.c
@@ -441,7 +441,7 @@ test_xdg_dirs (void)
 
   xdg = (gchar *)g_getenv ("XDG_CONFIG_DIRS");
   if (!xdg)
-    xdg = "/etc/xdg";
+    xdg = "/usr/local/etc/xdg:/etc/xdg";
 
   dirs = g_get_system_config_dirs ();
 
