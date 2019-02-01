--- src/gallium/winsys/amdgpu/drm/amdgpu_cs.c.orig	2019-01-31 21:05:07 UTC
+++ src/gallium/winsys/amdgpu/drm/amdgpu_cs.c
@@ -41,6 +41,10 @@
 #define AMDGPU_CHUNK_ID_BO_HANDLES 0x06
 #endif
 
+#ifdef __sun__
+#include <alloca.h>
+#endif
+
 DEBUG_GET_ONCE_BOOL_OPTION(noop, "RADEON_NOOP", false)
 
 /* FENCES */
