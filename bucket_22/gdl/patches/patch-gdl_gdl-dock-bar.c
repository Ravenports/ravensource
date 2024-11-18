--- gdl/gdl-dock-bar.c.orig	2018-10-22 19:36:04 UTC
+++ gdl/gdl-dock-bar.c
@@ -425,7 +425,7 @@ gdl_dock_bar_set_master (GdlDockBar    *
         if (GDL_IS_DOCK_OBJECT (master)) {
             master = gdl_dock_object_get_master (GDL_DOCK_OBJECT (master));
         }
-        dockbar->priv->master = g_object_ref (master);
+        dockbar->priv->master = (GdlDockMaster *)g_object_ref (master);
         dockbar->priv->layout_changed_id =
             g_signal_connect (dockbar->priv->master, "layout-changed",
                               (GCallback) gdl_dock_bar_layout_changed_cb,
