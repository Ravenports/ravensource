--- src/gallium/drivers/radeonsi/si_state_shaders.c.orig	2021-04-07 16:36:56 UTC
+++ src/gallium/drivers/radeonsi/si_state_shaders.c
@@ -2098,6 +2098,7 @@ static void si_build_shader_variant(stru
       return;
    }
 
+#ifndef __sun
    if (shader->compiler_ctx_state.is_debug_context) {
       FILE *f = open_memstream(&shader->shader_log, &shader->shader_log_size);
       if (f) {
@@ -2105,6 +2106,7 @@ static void si_build_shader_variant(stru
          fclose(f);
       }
    }
+#endif
 
    si_shader_init_pm4_state(sscreen, shader);
 }
