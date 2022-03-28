--- glib/tests/utils.c.orig	2022-03-17 15:01:31 UTC
+++ glib/tests/utils.c
@@ -708,7 +708,7 @@ test_xdg_dirs (void)
 
   xdg = (gchar *)g_getenv ("XDG_CONFIG_DIRS");
   if (!xdg)
-    xdg = "/etc/xdg";
+    xdg = "/usr/local/etc/xdg:/etc/xdg";
 
   dirs = g_get_system_config_dirs ();
 
