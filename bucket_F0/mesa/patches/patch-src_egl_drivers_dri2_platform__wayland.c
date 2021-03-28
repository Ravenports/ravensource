--- src/egl/drivers/dri2/platform_wayland.c.orig	2021-03-24 22:32:51 UTC
+++ src/egl/drivers/dri2/platform_wayland.c
@@ -1339,6 +1339,7 @@ registry_handle_global_drm(void *data, s
       dri2_dpy->wl_drm =
          wl_registry_bind(registry, name, &wl_drm_interface, MIN2(version, 2));
       wl_drm_add_listener(dri2_dpy->wl_drm, &drm_listener, dri2_dpy);
+#ifndef __DragonFly__
    } else if (strcmp(interface, "zwp_linux_dmabuf_v1") == 0 && version >= 3) {
       dri2_dpy->wl_dmabuf =
          wl_registry_bind(registry, name, &zwp_linux_dmabuf_v1_interface,
@@ -1346,6 +1347,7 @@ registry_handle_global_drm(void *data, s
       zwp_linux_dmabuf_v1_add_listener(dri2_dpy->wl_dmabuf, &dmabuf_listener,
                                        dri2_dpy);
    }
+#endif
 }
 
 static void
