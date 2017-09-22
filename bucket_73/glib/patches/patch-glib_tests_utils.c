--- glib/tests/utils.c.orig	2016-10-22 05:21:44 UTC
+++ glib/tests/utils.c
@@ -440,7 +440,7 @@ test_xdg_dirs (void)
 
   xdg = (gchar *)g_getenv ("XDG_CONFIG_DIRS");
   if (!xdg)
-    xdg = "/etc/xdg";
+    xdg = "/usr/local/etc/xdg:/etc/xdg";
 
   dirs = g_get_system_config_dirs ();
 
