- Define CLOCK_MONOTONIC_RAW if missing

--- src/amd/vulkan/radv_device.c.orig	2021-04-21 17:41:10 UTC
+++ src/amd/vulkan/radv_device.c
@@ -100,6 +100,14 @@ static uint64_t radv_get_absolute_timeou
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
