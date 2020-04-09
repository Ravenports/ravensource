--- glib/tests/utils.c.orig	2020-04-09 13:43:10 UTC
+++ glib/tests/utils.c
@@ -483,7 +483,7 @@ test_xdg_dirs (void)
 
   xdg = (gchar *)g_getenv ("XDG_CONFIG_DIRS");
   if (!xdg)
-    xdg = "/etc/xdg";
+    xdg = "/usr/local/etc/xdg:/etc/xdg";
 
   dirs = g_get_system_config_dirs ();
 
