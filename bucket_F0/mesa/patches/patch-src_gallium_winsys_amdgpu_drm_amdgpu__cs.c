--- src/gallium/winsys/amdgpu/drm/amdgpu_cs.c.orig	2024-05-08 13:28:59 UTC
+++ src/gallium/winsys/amdgpu/drm/amdgpu_cs.c
@@ -13,6 +13,10 @@
 
 #include "amd/common/sid.h"
 
+#ifdef __sun__
+#include <alloca.h>
+#endif
+
 /* FENCES */
 
 static struct pipe_fence_handle *
