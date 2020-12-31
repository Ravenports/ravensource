--- src/mesa/drivers/dri/i965/brw_program_binary.c.orig	2020-12-31 03:59:58 UTC
+++ src/mesa/drivers/dri/i965/brw_program_binary.c
@@ -36,9 +36,11 @@ static uint8_t driver_sha1[20];
 void
 brw_program_binary_init(unsigned device_id)
 {
+#ifdef HAVE_DL_ITERATE_PHDR
    const struct build_id_note *note =
       build_id_find_nhdr_for_addr(brw_program_binary_init);
    assert(note);
+#endif
 
    /**
     * With Mesa's megadrivers, taking the sha1 of i965_dri.so may not be
@@ -52,7 +54,9 @@ brw_program_binary_init(unsigned device_
    int len = snprintf(renderer, sizeof(renderer), "i965_%04x", device_id);
    assert(len == sizeof(renderer) - 1);
    _mesa_sha1_update(&ctx, renderer, len);
+#ifdef HAVE_DL_ITERATE_PHDR
    _mesa_sha1_update(&ctx, build_id_data(note), build_id_length(note));
+#endif
    _mesa_sha1_final(&ctx, driver_sha1);
 }
 
