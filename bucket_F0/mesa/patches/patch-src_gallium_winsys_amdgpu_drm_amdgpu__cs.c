--- src/gallium/winsys/amdgpu/drm/amdgpu_cs.c.orig	2024-04-24 18:00:13 UTC
+++ src/gallium/winsys/amdgpu/drm/amdgpu_cs.c
@@ -13,6 +13,10 @@
 
 #include "amd/common/sid.h"
 
+#ifdef __sun__
+#include <alloca.h>
+#endif
+
 /* FENCES */
 
 static struct pipe_fence_handle *
