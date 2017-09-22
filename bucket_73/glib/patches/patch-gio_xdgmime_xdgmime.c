--- gio/xdgmime/xdgmime.c.orig	2017-07-13 23:03:39 UTC
+++ gio/xdgmime/xdgmime.c
@@ -255,7 +255,7 @@ xdg_run_command_on_dirs (XdgDirectoryFun
 
   xdg_data_dirs = getenv ("XDG_DATA_DIRS");
   if (xdg_data_dirs == NULL)
-    xdg_data_dirs = "/usr/local/share/:/usr/share/";
+    xdg_data_dirs = "/usr/local/share/";
 
   ptr = xdg_data_dirs;
 
