--- src/gallium/winsys/amdgpu/drm/amdgpu_cs.c.orig	2018-01-18 21:30:28 UTC
+++ src/gallium/winsys/amdgpu/drm/amdgpu_cs.c
@@ -36,6 +36,10 @@
 
 #include "amd/common/sid.h"
 
+#ifdef __sun__
+#include <alloca.h>
+#endif
+
 DEBUG_GET_ONCE_BOOL_OPTION(noop, "RADEON_NOOP", false)
 
 /* FENCES */
