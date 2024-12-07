--- xf86drmMode.c.orig	2024-12-04 18:30:30 UTC
+++ xf86drmMode.c
@@ -39,9 +39,7 @@
 #include <stdlib.h>
 #include <sys/ioctl.h>
 #if HAVE_SYS_SYSCTL_H
-#ifdef __FreeBSD__
 #include <sys/types.h>
-#endif
 #include <sys/sysctl.h>
 #endif
 #include <stdio.h>
@@ -1129,7 +1127,7 @@ drm_public int drmModePageFlipTarget(int
 
 drm_public int drmModeSetPlane(int fd, uint32_t plane_id, uint32_t crtc_id,
 		    uint32_t fb_id, uint32_t flags,
-		    int32_t crtc_x, int32_t crtc_y,
+		    uint32_t crtc_x, int32_t crtc_y,
 		    uint32_t crtc_w, uint32_t crtc_h,
 		    uint32_t src_x, uint32_t src_y,
 		    uint32_t src_w, uint32_t src_h)
