--- gtksourceview/gtksourceview.c.orig	2019-03-21 21:55:02 UTC
+++ gtksourceview/gtksourceview.c
@@ -1586,7 +1586,7 @@ set_source_buffer (GtkSourceView *view,
 	{
 		GtkSourceBufferInternal *buffer_internal;
 
-		view->priv->source_buffer = g_object_ref (buffer);
+		view->priv->source_buffer = (GtkSourceBuffer *)g_object_ref (buffer);
 
 		g_signal_connect (buffer,
 				  "highlight-updated",
