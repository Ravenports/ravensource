--- src/mesa/drivers/dri/i965/brw_disk_cache.c.orig	2018-07-13 18:41:27 UTC
+++ src/mesa/drivers/dri/i965/brw_disk_cache.c
@@ -422,6 +422,7 @@ void
 brw_disk_cache_init(struct intel_screen *screen)
 {
 #ifdef ENABLE_SHADER_CACHE
+# ifdef HAVE_DL_ITERATE_PHDR
    char renderer[10];
    MAYBE_UNUSED int len = snprintf(renderer, sizeof(renderer), "i965_%04x",
                                    screen->deviceID);
@@ -438,5 +439,6 @@ brw_disk_cache_init(struct intel_screen
    _mesa_sha1_format(timestamp, id_sha1);
 
    screen->disk_cache = disk_cache_create(renderer, timestamp, 0);
+# endif
 #endif
 }
