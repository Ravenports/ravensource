--- src/amd/common/ac_linux_drm.h.orig	2026-04-15 14:20:41 UTC
+++ src/amd/common/ac_linux_drm.h
@@ -9,6 +9,10 @@
 #include <stdbool.h>
 #include <stdint.h>
 
+#if defined(__sun__)
+#include <alloca.h>
+#endif
+
 #if !defined(_WIN32)
 #include "drm-uapi/amdgpu_drm.h"
 #include "amdgpu.h"
