--- src/gallium/winsys/amdgpu/drm/amdgpu_cs.c.orig	2018-10-31 18:26:26 UTC
+++ src/gallium/winsys/amdgpu/drm/amdgpu_cs.c
@@ -37,6 +37,10 @@
 #define AMDGPU_IB_FLAG_TC_WB_NOT_INVALIDATE (1 << 3)
 #endif
 
+#ifdef __sun__
+#include <alloca.h>
+#endif
+
 DEBUG_GET_ONCE_BOOL_OPTION(noop, "RADEON_NOOP", false)
 
 /* FENCES */
