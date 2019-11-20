--- glib/tests/utils.c.orig	2019-11-19 17:51:31 UTC
+++ glib/tests/utils.c
@@ -480,7 +480,7 @@ test_xdg_dirs (void)
 
   xdg = (gchar *)g_getenv ("XDG_CONFIG_DIRS");
   if (!xdg)
-    xdg = "/etc/xdg";
+    xdg = "/usr/local/etc/xdg:/etc/xdg";
 
   dirs = g_get_system_config_dirs ();
 
