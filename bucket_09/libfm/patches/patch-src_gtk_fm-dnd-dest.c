--- src/gtk/fm-dnd-dest.c.orig	2018-04-16 19:11:33 UTC
+++ src/gtk/fm-dnd-dest.c
@@ -458,7 +458,7 @@ static GdkDragAction _ask_action_on_drop
             gtk_action_set_sensitive(act, FALSE);
         }
     }
-    ri.menu = g_object_ref(gtk_ui_manager_get_widget(ui, "/popup"));
+    ri.menu = (GtkMenu *)g_object_ref(gtk_ui_manager_get_widget(ui, "/popup"));
     g_signal_connect(ri.menu, "selection-done", G_CALLBACK(gtk_widget_destroy), NULL);
     unmap_handler = g_signal_connect(ri.menu, "unmap",
                                      G_CALLBACK(run_unmap_handler), &ri);
