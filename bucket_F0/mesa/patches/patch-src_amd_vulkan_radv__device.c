- Define CLOCK_MONOTONIC_RAW if missing

--- src/amd/vulkan/radv_device.c.orig	2022-08-17 16:53:25 UTC
+++ src/amd/vulkan/radv_device.c
@@ -97,6 +97,14 @@ radv_get_current_time(void)
    return os_time_get_nano();
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
 radv_device_get_cache_uuid(struct radv_physical_device *pdevice, void *uuid)
 {
