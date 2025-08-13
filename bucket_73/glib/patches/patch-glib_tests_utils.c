--- glib/tests/utils.c.orig	2025-06-13 11:55:59 UTC
+++ glib/tests/utils.c
@@ -873,7 +873,7 @@ test_xdg_dirs (void)
 
   xdg = (gchar *)g_getenv ("XDG_CONFIG_DIRS");
   if (!xdg)
-    xdg = "/etc/xdg";
+    xdg = "/usr/local/etc/xdg:/etc/xdg";
 
   dirs = g_get_system_config_dirs ();
 
