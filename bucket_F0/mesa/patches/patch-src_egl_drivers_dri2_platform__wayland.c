--- src/egl/drivers/dri2/platform_wayland.c.orig	2025-06-18 17:45:40 UTC
+++ src/egl/drivers/dri2/platform_wayland.c
@@ -2096,6 +2096,7 @@ registry_handle_global_drm(void *data, s
    if (strcmp(interface, wl_drm_interface.name) == 0) {
       dri2_dpy->wl_drm_version = MIN2(version, 2);
       dri2_dpy->wl_drm_name = name;
+#ifndef __DragonFly__
    } else if (strcmp(interface, zwp_linux_dmabuf_v1_interface.name) == 0 &&
               version >= 3) {
       dri2_dpy->wl_dmabuf = wl_registry_bind(
@@ -2103,6 +2104,7 @@ registry_handle_global_drm(void *data, s
          MIN2(version, ZWP_LINUX_DMABUF_V1_GET_DEFAULT_FEEDBACK_SINCE_VERSION));
       zwp_linux_dmabuf_v1_add_listener(dri2_dpy->wl_dmabuf, &dmabuf_listener,
                                        dri2_dpy);
+#endif
    }
 }
 
