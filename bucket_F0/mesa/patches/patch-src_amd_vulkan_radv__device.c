- Define CLOCK_MONOTONIC_RAW if missing

--- src/amd/vulkan/radv_device.c.orig	2021-10-14 19:59:05 UTC
+++ src/amd/vulkan/radv_device.c
@@ -106,6 +106,14 @@ radv_get_absolute_timeout(uint64_t timeo
    return current_time + timeout;
 }
 
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
