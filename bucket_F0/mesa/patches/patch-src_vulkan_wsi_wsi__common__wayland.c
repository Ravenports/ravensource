wayland 1.22

https://gitlab.freedesktop.org/mesa/mesa/-/commit/ee5d2250fd15
https://gitlab.freedesktop.org/mesa/mesa/-/commit/689ce66a4332

--- src/vulkan/wsi/wsi_common_wayland.c.orig	2023-03-08 18:37:09 UTC
+++ src/vulkan/wsi/wsi_common_wayland.c
@@ -1156,12 +1156,6 @@ wsi_wl_surface_destroy(VkIcdSurfaceBase
    struct wsi_wl_surface *wsi_wl_surface =
       wl_container_of((VkIcdSurfaceWayland *)icd_surface, wsi_wl_surface, base);
 
-   if (wsi_wl_surface->surface)
-      wl_proxy_wrapper_destroy(wsi_wl_surface->surface);
-
-   if (wsi_wl_surface->display)
-      wsi_wl_display_destroy(wsi_wl_surface->display);
-
    if (wsi_wl_surface->wl_dmabuf_feedback) {
       zwp_linux_dmabuf_feedback_v1_destroy(wsi_wl_surface->wl_dmabuf_feedback);
       dmabuf_feedback_fini(&wsi_wl_surface->dmabuf_feedback);
