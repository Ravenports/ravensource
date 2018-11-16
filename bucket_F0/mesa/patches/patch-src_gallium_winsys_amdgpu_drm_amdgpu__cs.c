--- src/gallium/winsys/amdgpu/drm/amdgpu_cs.c.orig	2018-11-15 12:32:30 UTC
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
