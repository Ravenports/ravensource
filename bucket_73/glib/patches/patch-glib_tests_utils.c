--- glib/tests/utils.c.orig	2025-02-20 13:08:16 UTC
+++ glib/tests/utils.c
@@ -869,7 +869,7 @@ test_xdg_dirs (void)
 
   xdg = (gchar *)g_getenv ("XDG_CONFIG_DIRS");
   if (!xdg)
-    xdg = "/etc/xdg";
+    xdg = "/usr/local/etc/xdg:/etc/xdg";
 
   dirs = g_get_system_config_dirs ();
 
