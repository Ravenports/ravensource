--- src/gallium/winsys/amdgpu/drm/amdgpu_cs.c.orig	2020-12-16 18:43:56 UTC
+++ src/gallium/winsys/amdgpu/drm/amdgpu_cs.c
@@ -33,6 +33,10 @@
 
 #include "amd/common/sid.h"
 
+#ifdef __sun__
+#include <alloca.h>
+#endif
+
 DEBUG_GET_ONCE_BOOL_OPTION(noop, "RADEON_NOOP", false)
 
 /* FENCES */
