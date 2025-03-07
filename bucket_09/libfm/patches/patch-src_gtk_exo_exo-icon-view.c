--- src/gtk/exo/exo-icon-view.c.orig	2021-01-29 21:02:49 UTC
+++ src/gtk/exo/exo-icon-view.c
@@ -2819,7 +2819,7 @@ exo_icon_view_key_press_event (GtkWidget
   /* allocate a new event to forward */
   new_event = gdk_event_copy ((GdkEvent *) event);
   g_object_unref (G_OBJECT (new_event->key.window));
-  new_event->key.window = g_object_ref (G_OBJECT (gtk_widget_get_window (icon_view->priv->search_entry)));
+  new_event->key.window = (GdkWindow *)g_object_ref (G_OBJECT (gtk_widget_get_window (icon_view->priv->search_entry)));
 
   /* send the event to the search entry. If the "preedit-changed" signal is
    * emitted during this event, priv->search_imcontext_changed will be set.
