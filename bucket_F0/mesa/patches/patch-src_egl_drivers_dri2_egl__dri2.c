--- src/egl/drivers/dri2/egl_dri2.c.orig	2020-04-29 22:48:24 UTC
+++ src/egl/drivers/dri2/egl_dri2.c
@@ -965,6 +965,7 @@ dri2_setup_screen(_EGLDisplay *disp)
              disp->Extensions.KHR_gl_texture_3D_image = EGL_TRUE;
       }
 #ifdef HAVE_LIBDRM
+# ifndef __DragonFly__
       if (dri2_dpy->image->base.version >= 8 &&
           dri2_dpy->image->createImageFromDmaBufs) {
          disp->Extensions.EXT_image_dma_buf_import = EGL_TRUE;
@@ -975,6 +976,7 @@ dri2_setup_screen(_EGLDisplay *disp)
           dri2_dpy->image->queryDmaBufModifiers) {
          disp->Extensions.EXT_image_dma_buf_import_modifiers = EGL_TRUE;
       }
+# endif
 #endif
    }
 
