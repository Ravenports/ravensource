--- src/gallium/winsys/svga/drm/vmw_screen_ioctl.c.orig	2018-01-18 21:30:28 UTC
+++ src/gallium/winsys/svga/drm/vmw_screen_ioctl.c
@@ -70,6 +70,11 @@ vmw_region_size(struct vmw_region *regio
    return region->size;
 }
 
+#if defined(__DragonFly__) || defined(__FreeBSD__) || \
+    defined(__NetBSD__) || defined(__OpenBSD__)
+#define ERESTART EINTR
+#endif
+
 uint32
 vmw_ioctl_context_create(struct vmw_winsys_screen *vws)
 {
