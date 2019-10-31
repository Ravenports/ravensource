--- panel-plugins/power-manager-plugin/xfce/xfce-power-manager-plugin.c.orig	2019-08-02 03:32:48 UTC
+++ panel-plugins/power-manager-plugin/xfce/xfce-power-manager-plugin.c
@@ -33,7 +33,6 @@
 
 #ifdef XFCE_PLUGIN
 #include <libxfce4panel/libxfce4panel.h>
-#include <libxfce4panel/xfce-panel-plugin.h>
 #include <libxfce4ui/libxfce4ui.h>
 #include <libxfce4util/libxfce4util.h>
 #include <xfconf/xfconf.h>
@@ -227,7 +226,7 @@ power_manager_plugin_new (XfcePanelPlugi
     XfconfChannel *channel;
 
     /* allocate memory for the plugin structure */
-    power_manager_plugin = panel_slice_new0 (PowerManagerPlugin);
+    power_manager_plugin = g_slice_new0 (PowerManagerPlugin);
 
     /* pointer to plugin */
     power_manager_plugin->plugin = plugin;
