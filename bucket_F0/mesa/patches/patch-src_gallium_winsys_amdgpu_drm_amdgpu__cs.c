--- src/gallium/winsys/amdgpu/drm/amdgpu_cs.c.orig	2021-10-14 19:59:05 UTC
+++ src/gallium/winsys/amdgpu/drm/amdgpu_cs.c
@@ -33,6 +33,10 @@
 
 #include "amd/common/sid.h"
 
+#ifdef __sun__
+#include <alloca.h>
+#endif
+
 /* FENCES */
 
 static struct pipe_fence_handle *
