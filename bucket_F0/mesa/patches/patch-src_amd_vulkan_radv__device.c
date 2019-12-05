- Define CLOCK_MONOTONIC_RAW if missing

--- src/amd/vulkan/radv_device.c.orig	2019-12-04 22:10:12 UTC
+++ src/amd/vulkan/radv_device.c
@@ -49,6 +49,14 @@
 #include "compiler/glsl_types.h"
 #include "util/xmlpool.h"
 
+#ifndef CLOCK_MONOTONIC_RAW
+# ifdef CLOCK_MONOTONIC_FAST
+#  define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC_FAST
+# else
+#  define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC
+# endif
+#endif
+
 static int
 radv_device_get_cache_uuid(enum radeon_family family, void *uuid)
 {
