--- src/gallium/winsys/amdgpu/drm/amdgpu_cs.c.orig	2021-09-29 20:10:17 UTC
+++ src/gallium/winsys/amdgpu/drm/amdgpu_cs.c
@@ -33,6 +33,10 @@
 
 #include "amd/common/sid.h"
 
+#ifdef __sun__
+#include <alloca.h>
+#endif
+
 /* FENCES */
 
 static struct pipe_fence_handle *
