--- src/egl/drivers/dri2/platform_wayland.c.orig	2023-04-20 23:06:54 UTC
+++ src/egl/drivers/dri2/platform_wayland.c
@@ -1948,12 +1948,14 @@ registry_handle_global_drm(void *data, s
    if (strcmp(interface, wl_drm_interface.name) == 0) {
       dri2_dpy->wl_drm_version = MIN2(version, 2);
       dri2_dpy->wl_drm_name = name;
+#ifndef __DragonFly__
    } else if (strcmp(interface, zwp_linux_dmabuf_v1_interface.name) == 0 && version >= 3) {
       dri2_dpy->wl_dmabuf =
          wl_registry_bind(registry, name, &zwp_linux_dmabuf_v1_interface,
                           MIN2(version, ZWP_LINUX_DMABUF_V1_GET_DEFAULT_FEEDBACK_SINCE_VERSION));
       zwp_linux_dmabuf_v1_add_listener(dri2_dpy->wl_dmabuf, &dmabuf_listener,
                                        dri2_dpy);
+#endif
    }
 }
 
@@ -2800,10 +2802,10 @@ dri2_teardown_wayland(struct dri2_egl_di
       wl_shm_destroy(dri2_dpy->wl_shm);
    if (dri2_dpy->wl_registry)
       wl_registry_destroy(dri2_dpy->wl_registry);
-   if (dri2_dpy->wl_queue)
-      wl_event_queue_destroy(dri2_dpy->wl_queue);
    if (dri2_dpy->wl_dpy_wrapper)
       wl_proxy_wrapper_destroy(dri2_dpy->wl_dpy_wrapper);
+   if (dri2_dpy->wl_queue)
+      wl_event_queue_destroy(dri2_dpy->wl_queue);
 
    if (dri2_dpy->own_device)
       wl_display_disconnect(dri2_dpy->wl_dpy);
