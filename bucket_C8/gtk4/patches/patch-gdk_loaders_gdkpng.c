--- gdk/loaders/gdkpng.c.orig	2024-11-01 17:50:49 UTC
+++ gdk/loaders/gdkpng.c
@@ -312,7 +312,7 @@ gdk_load_png (GBytes      *bytes,
   png_set_read_fn (png, &io, png_read_func);
   png_set_read_user_chunk_fn (png, &cicp, png_read_chunk_func);
 
-  if (sigsetjmp (png_jmpbuf (png), 1))
+  if (sigsetjmp ((struct _sigjmp_buf *)png_jmpbuf (png), 1))
     {
       g_free (buffer);
       g_free (row_pointers);
@@ -607,7 +607,7 @@ gdk_save_png (GdkTexture *texture)
   gdk_color_state_ref (color_state);
   bytes = NULL;
 
-  if (sigsetjmp (png_jmpbuf (png), 1))
+  if (sigsetjmp ((struct _sigjmp_buf *)png_jmpbuf (png), 1))
     {
       gdk_color_state_unref (color_state);
       g_clear_pointer (&bytes, g_bytes_unref);
