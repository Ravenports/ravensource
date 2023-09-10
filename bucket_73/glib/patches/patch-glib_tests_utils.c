--- glib/tests/utils.c.orig	2023-09-08 13:42:18 UTC
+++ glib/tests/utils.c
@@ -848,7 +848,7 @@ test_xdg_dirs (void)
 
   xdg = (gchar *)g_getenv ("XDG_CONFIG_DIRS");
   if (!xdg)
-    xdg = "/etc/xdg";
+    xdg = "/usr/local/etc/xdg:/etc/xdg";
 
   dirs = g_get_system_config_dirs ();
 
