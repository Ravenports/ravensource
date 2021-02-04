--- glib/tests/utils.c.orig	2021-02-03 15:28:40 UTC
+++ glib/tests/utils.c
@@ -485,7 +485,7 @@ test_xdg_dirs (void)
 
   xdg = (gchar *)g_getenv ("XDG_CONFIG_DIRS");
   if (!xdg)
-    xdg = "/etc/xdg";
+    xdg = "/usr/local/etc/xdg:/etc/xdg";
 
   dirs = g_get_system_config_dirs ();
 
