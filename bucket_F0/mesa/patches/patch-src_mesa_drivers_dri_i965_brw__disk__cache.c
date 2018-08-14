--- src/mesa/drivers/dri/i965/brw_disk_cache.c.orig	2018-08-13 16:42:38 UTC
+++ src/mesa/drivers/dri/i965/brw_disk_cache.c
@@ -425,6 +425,7 @@ brw_disk_cache_init(struct intel_screen
    if (INTEL_DEBUG & DEBUG_DISK_CACHE_DISABLE_MASK)
       return;
 
+# ifdef HAVE_DL_ITERATE_PHDR
    char renderer[10];
    MAYBE_UNUSED int len = snprintf(renderer, sizeof(renderer), "i965_%04x",
                                    screen->deviceID);
@@ -442,5 +443,6 @@ brw_disk_cache_init(struct intel_screen
 
    const uint64_t driver_flags = INTEL_DEBUG & DEBUG_DISK_CACHE_MASK;
    screen->disk_cache = disk_cache_create(renderer, timestamp, driver_flags);
+# endif
 #endif
 }
