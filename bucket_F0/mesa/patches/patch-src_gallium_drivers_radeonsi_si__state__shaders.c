--- src/gallium/drivers/radeonsi/si_state_shaders.c.orig	2021-06-30 18:18:55 UTC
+++ src/gallium/drivers/radeonsi/si_state_shaders.c
@@ -2129,6 +2129,7 @@ static void si_build_shader_variant(stru
       return;
    }
 
+#ifndef __sun
    if (shader->compiler_ctx_state.is_debug_context) {
       FILE *f = open_memstream(&shader->shader_log, &shader->shader_log_size);
       if (f) {
@@ -2136,6 +2137,7 @@ static void si_build_shader_variant(stru
          fclose(f);
       }
    }
+#endif
 
    si_shader_init_pm4_state(sscreen, shader);
 }
