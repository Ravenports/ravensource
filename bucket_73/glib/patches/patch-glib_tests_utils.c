--- glib/tests/utils.c.orig	2020-05-20 10:46:43 UTC
+++ glib/tests/utils.c
@@ -483,7 +483,7 @@ test_xdg_dirs (void)
 
   xdg = (gchar *)g_getenv ("XDG_CONFIG_DIRS");
   if (!xdg)
-    xdg = "/etc/xdg";
+    xdg = "/usr/local/etc/xdg:/etc/xdg";
 
   dirs = g_get_system_config_dirs ();
 
