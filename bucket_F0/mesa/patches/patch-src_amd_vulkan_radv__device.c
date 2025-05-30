- Define CLOCK_MONOTONIC_RAW if missing

--- src/amd/vulkan/radv_device.c.orig	2025-04-30 17:18:00 UTC
+++ src/amd/vulkan/radv_device.c
@@ -430,6 +430,14 @@ radv_parse_force_vrs_config_file(const c
 
 #define BUF_LEN ((10 * (sizeof(struct inotify_event) + NAME_MAX + 1)))
 
+#ifndef CLOCK_MONOTONIC_RAW
+# ifdef CLOCK_MONOTONIC_FAST
+#  define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC_FAST
+# else
+#  define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC
+# endif
+#endif
+
 static int
 radv_notifier_thread_run(void *data)
 {
