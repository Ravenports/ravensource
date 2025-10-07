--- gdk/loaders/gdkpng.c.orig	2025-09-30 10:19:25 UTC
+++ gdk/loaders/gdkpng.c
@@ -345,7 +345,11 @@ gdk_load_png (GBytes      *bytes,
   png_set_read_user_chunk_fn (png, &cicp, png_read_chunk_func);
 #endif
 
+#if defined(__linux__) || defined(__NetBSD__)
   if (sigsetjmp (png_jmpbuf (png), 1))
+#else
+  if (sigsetjmp ((struct _sigjmp_buf *)png_jmpbuf (png), 1))
+#endif
     {
       g_free (buffer);
       g_free (row_pointers);
@@ -664,7 +668,11 @@ gdk_save_png (GdkTexture *texture,
   gdk_color_state_ref (color_state);
   bytes = NULL;
 
+#if defined(__linux__) || defined(__NetBSD__)
   if (sigsetjmp (png_jmpbuf (png), 1))
+#else
+  if (sigsetjmp ((struct _sigjmp_buf *)png_jmpbuf (png), 1))
+#endif
     {
       gdk_color_state_unref (color_state);
       g_clear_pointer (&bytes, g_bytes_unref);
