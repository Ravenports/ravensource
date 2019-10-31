--- panel-plugin/notification-plugin.c.orig	2018-12-02 23:38:32 UTC
+++ panel-plugin/notification-plugin.c
@@ -27,7 +27,7 @@
 #include <gtk/gtk.h>
 #include <xfconf/xfconf.h>
 #include <libxfce4util/libxfce4util.h>
-#include <libxfce4panel/xfce-panel-plugin.h>
+#include <libxfce4panel/libxfce4panel.h>
 
 #include "notification-plugin.h"
 #include "notification-plugin-log.h"
@@ -201,7 +201,7 @@ notification_plugin_new (XfcePanelPlugin
   gboolean               state;
 
   /* Allocate memory for the plugin structure */
-  notification_plugin = panel_slice_new0 (NotificationPlugin);
+  notification_plugin = g_slice_new0 (NotificationPlugin);
   notification_plugin->plugin = panel_plugin;
 
   /* Initialize xfconf */
@@ -271,7 +271,7 @@ notification_plugin_free (XfcePanelPlugi
     g_source_remove (notification_plugin->menu_size_allocate_next_handler);
 
   /* free the plugin structure */
-  panel_slice_free (NotificationPlugin, notification_plugin);
+  g_slice_free (NotificationPlugin, notification_plugin);
 }
 
 
