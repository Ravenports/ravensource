--- src/gtk/fm-standard-view.c.orig	2018-04-16 19:11:33 UTC
+++ src/gtk/fm-standard-view.c
@@ -637,7 +637,7 @@ static inline void create_icon_view(FmSt
                                 "text", FM_FOLDER_MODEL_COL_NAME );
     if(fv->renderer_text)
         g_object_unref(fv->renderer_text);
-    fv->renderer_text = g_object_ref_sink(render);
+    fv->renderer_text = (FmCellRendererText *)g_object_ref_sink(render);
     exo_icon_view_set_search_column((ExoIconView*)fv->view, FM_FOLDER_MODEL_COL_NAME);
     g_signal_connect(fv->view, "item-activated", G_CALLBACK(on_icon_view_item_activated), fv);
     g_signal_connect(fv->view, "selection-changed", G_CALLBACK(on_sel_changed), fv);
