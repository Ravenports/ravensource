--- src/amd/common/nir/ac_nir_lower_image_tex.c.orig	2026-08-20 08:57:40 UTC
+++ src/amd/common/nir/ac_nir_lower_image_tex.c
@@ -99,7 +99,7 @@ replace_with_formatted_load_buffer_amd(n
                                          .dest_type = dest_type);
 
    if (old_def->bit_size == 64) {
-      nir_def **vec = alloca(sizeof(nir_def*) * old_def->num_components);
+      nir_def **vec = __builtin_alloca(sizeof(nir_def*) * old_def->num_components);
       nir_def *undef64 = nir_undef(b, 1, 64);
 
       /* The 64-bit result is: (xy, 0, 0, zw, sparse). */
@@ -133,7 +133,7 @@ replace_with_formatted_load_buffer_amd(n
       /* We removed unused components between the last used data component and the sparse flag.
        * Add the unused components back as undef.
        */
-      nir_def **vec = alloca(sizeof(nir_def*) * old_def->num_components);
+      nir_def **vec = __builtin_alloca(sizeof(nir_def*) * old_def->num_components);
       nir_def *undef = nir_undef(b, 1, old_def->bit_size);
       unsigned i = 0;
 
