/usr/local value is replaced by post-patch target

--- glib/gutils.c.orig	2025-06-13 11:55:59 UTC
+++ glib/gutils.c
@@ -30,6 +30,10 @@
 
 #include "config.h"
 
+#ifdef __sun__
+#  define	_POSIX_PTHREAD_SEMANTICS 1
+#  undef	HAVE_SYS_AUXV_H
+#endif
 #include "gutils.h"
 #include "gutilsprivate.h"
 
@@ -2701,7 +2705,7 @@ g_build_system_data_dirs (void)
    */
 #ifndef G_OS_WIN32
   if (!data_dirs || !data_dirs[0])
-    data_dirs = "/usr/local/share/:/usr/share/";
+    data_dirs = "/usr/local/share/";
 
   data_dir_vector = g_strsplit (data_dirs, G_SEARCHPATH_SEPARATOR_S, 0);
 #else
@@ -2798,7 +2802,7 @@ g_build_system_config_dirs (void)
     }
 #else
   if (!conf_dirs || !conf_dirs[0])
-    conf_dirs = "/etc/xdg";
+    conf_dirs = "/usr/local/etc/xdg:/etc/xdg";
 
   conf_dir_vector = g_strsplit (conf_dirs, G_SEARCHPATH_SEPARATOR_S, 0);
 #endif
