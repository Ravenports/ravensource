- Define CLOCK_MONOTONIC_RAW if missing

--- src/amd/vulkan/radv_device.c.orig	2022-11-07 18:01:13 UTC
+++ src/amd/vulkan/radv_device.c
@@ -111,6 +111,14 @@ parse_hex(char *out, const char *in, uns
    }
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
