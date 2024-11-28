--- src/amdgpu_glamor.c.orig	2023-02-22 17:14:50 UTC
+++ src/amdgpu_glamor.c
@@ -28,9 +28,10 @@
 #include "config.h"
 #endif
 
-#ifdef USE_GLAMOR
-
 #include <xf86.h>
+DevPrivateKeyRec amdgpu_pixmap_index;
+
+#ifdef USE_GLAMOR
 
 #include "amdgpu_bo_helper.h"
 #include "amdgpu_pixmap.h"
@@ -42,8 +43,6 @@
 #include <GL/gl.h>
 #endif
 
-DevPrivateKeyRec amdgpu_pixmap_index;
-
 void amdgpu_glamor_exchange_buffers(PixmapPtr src, PixmapPtr dst)
 {
 	AMDGPUInfoPtr info = AMDGPUPTR(xf86ScreenToScrn(dst->drawable.pScreen));
