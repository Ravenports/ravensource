--- src/egl/drivers/dri2/platform_wayland.c.orig	2022-06-16 16:17:53 UTC
+++ src/egl/drivers/dri2/platform_wayland.c
@@ -1913,12 +1913,14 @@ registry_handle_global_drm(void *data, s
    if (strcmp(interface, "wl_drm") == 0) {
       dri2_dpy->wl_drm_version = MIN2(version, 2);
       dri2_dpy->wl_drm_name = name;
+#ifndef __DragonFly__
    } else if (strcmp(interface, "zwp_linux_dmabuf_v1") == 0 && version >= 3) {
       dri2_dpy->wl_dmabuf =
          wl_registry_bind(registry, name, &zwp_linux_dmabuf_v1_interface,
                           MIN2(version, ZWP_LINUX_DMABUF_V1_GET_DEFAULT_FEEDBACK_SINCE_VERSION));
       zwp_linux_dmabuf_v1_add_listener(dri2_dpy->wl_dmabuf, &dmabuf_listener,
                                        dri2_dpy);
+#endif
    }
 }
 
