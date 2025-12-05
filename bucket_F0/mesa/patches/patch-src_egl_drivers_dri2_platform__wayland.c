--- src/egl/drivers/dri2/platform_wayland.c.orig	2025-12-04 06:02:48 UTC
+++ src/egl/drivers/dri2/platform_wayland.c
@@ -2289,6 +2289,7 @@ registry_handle_global_drm(void *data, s
       dri2_dpy->wl_drm_name = name;
    } else
 #endif
+#ifndef __DragonFly__
    if (strcmp(interface, zwp_linux_dmabuf_v1_interface.name) == 0 &&
               version >= 3) {
       dri2_dpy->wl_dmabuf = wl_registry_bind(
@@ -2296,7 +2297,9 @@ registry_handle_global_drm(void *data, s
          MIN2(version, ZWP_LINUX_DMABUF_V1_GET_DEFAULT_FEEDBACK_SINCE_VERSION));
       zwp_linux_dmabuf_v1_add_listener(dri2_dpy->wl_dmabuf, &dmabuf_listener,
                                        dri2_dpy);
-   } else if (strcmp(interface, wp_presentation_interface.name) == 0) {
+   } else 
+@endif
+      if (strcmp(interface, wp_presentation_interface.name) == 0) {
       dri2_dpy->wp_presentation =
          wl_registry_bind(registry, name, &wp_presentation_interface, 1);
       wp_presentation_add_listener(dri2_dpy->wp_presentation,
