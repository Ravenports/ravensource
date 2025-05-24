--- glib/tests/utils.c.orig	2025-05-20 16:22:25 UTC
+++ glib/tests/utils.c
@@ -873,7 +873,7 @@ test_xdg_dirs (void)
 
   xdg = (gchar *)g_getenv ("XDG_CONFIG_DIRS");
   if (!xdg)
-    xdg = "/etc/xdg";
+    xdg = "/usr/local/etc/xdg:/etc/xdg";
 
   dirs = g_get_system_config_dirs ();
 
