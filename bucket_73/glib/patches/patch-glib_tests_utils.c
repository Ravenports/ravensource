--- glib/tests/utils.c.orig	2023-10-25 11:33:59 UTC
+++ glib/tests/utils.c
@@ -850,7 +850,7 @@ test_xdg_dirs (void)
 
   xdg = (gchar *)g_getenv ("XDG_CONFIG_DIRS");
   if (!xdg)
-    xdg = "/etc/xdg";
+    xdg = "/usr/local/etc/xdg:/etc/xdg";
 
   dirs = g_get_system_config_dirs ();
 
