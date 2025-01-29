--- src/egl/drivers/dri2/egl_dri2.c.orig	2025-01-22 18:12:23 UTC
+++ src/egl/drivers/dri2/egl_dri2.c
@@ -725,6 +725,7 @@ dri2_setup_screen(_EGLDisplay *disp)
    disp->Extensions.MESA_drm_image = (capabilities & __DRI_IMAGE_CAP_GLOBAL_NAMES) != 0;
 
 #ifdef HAVE_LIBDRM
+# ifndef __DragonFly__
    if (dri_get_screen_param(dri2_dpy->dri_screen_render_gpu, PIPE_CAP_DMABUF) & DRM_PRIME_CAP_EXPORT)
       disp->Extensions.MESA_image_dma_buf_export = true;
 
@@ -732,6 +733,7 @@ dri2_setup_screen(_EGLDisplay *disp)
       disp->Extensions.EXT_image_dma_buf_import = EGL_TRUE;
       disp->Extensions.EXT_image_dma_buf_import_modifiers = EGL_TRUE;
    }
+# endif
 #endif
    disp->Extensions.MESA_x11_native_visual_id = EGL_TRUE;
    disp->Extensions.EXT_surface_compression = EGL_TRUE;
