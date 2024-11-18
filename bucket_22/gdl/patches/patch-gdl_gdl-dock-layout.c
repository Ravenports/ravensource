--- gdl/gdl-dock-layout.c.orig	2018-10-22 19:36:04 UTC
+++ gdl/gdl-dock-layout.c
@@ -27,6 +27,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include <libxml/parser.h>
+#include <libxml/xmlsave.h>
 #include <gtk/gtk.h>
 
 #include "gdl-dock-layout.h"
@@ -620,7 +621,7 @@ gdl_dock_layout_set_master (GdlDockLayou
         if (GDL_IS_DOCK_OBJECT (master)) {
             master = gdl_dock_object_get_master (GDL_DOCK_OBJECT (master));
         }
-        layout->priv->master = g_object_ref (master);
+        layout->priv->master = (GdlDockMaster *)g_object_ref (master);
         layout->priv->layout_changed_id =
             g_signal_connect (layout->priv->master, "layout-changed",
                               (GCallback) gdl_dock_layout_layout_changed_cb,
