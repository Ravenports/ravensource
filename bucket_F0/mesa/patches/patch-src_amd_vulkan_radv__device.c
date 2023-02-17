- Define CLOCK_MONOTONIC_RAW if missing

--- src/amd/vulkan/radv_device.c.orig	2023-02-08 21:05:36 UTC
+++ src/amd/vulkan/radv_device.c
@@ -104,6 +104,14 @@ parse_hex(char *out, const char *in, uns
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
