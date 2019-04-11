--- src/mesa/drivers/dri/i965/brw_disk_cache.c.orig	2019-04-11 03:36:10 UTC
+++ src/mesa/drivers/dri/i965/brw_disk_cache.c
@@ -380,6 +380,7 @@ brw_disk_cache_init(struct intel_screen
    if (INTEL_DEBUG & DEBUG_DISK_CACHE_DISABLE_MASK)
       return;
 
+# ifdef HAVE_DL_ITERATE_PHDR
    /* array length: print length + null char + 1 extra to verify it is unused */
    char renderer[11];
    MAYBE_UNUSED int len = snprintf(renderer, sizeof(renderer), "i965_%04x",
@@ -399,5 +400,6 @@ brw_disk_cache_init(struct intel_screen
    const uint64_t driver_flags =
       brw_get_compiler_config_value(screen->compiler);
    screen->disk_cache = disk_cache_create(renderer, timestamp, driver_flags);
+# endif
 #endif
 }
