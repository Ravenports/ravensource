--- src/gallium/drivers/radeonsi/si_state_shaders.c.orig	2021-03-24 19:10:48 UTC
+++ src/gallium/drivers/radeonsi/si_state_shaders.c
@@ -2093,6 +2093,7 @@ static void si_build_shader_variant(stru
       return;
    }
 
+#ifndef __sun
    if (shader->compiler_ctx_state.is_debug_context) {
       FILE *f = open_memstream(&shader->shader_log, &shader->shader_log_size);
       if (f) {
@@ -2100,6 +2101,7 @@ static void si_build_shader_variant(stru
          fclose(f);
       }
    }
+#endif
 
    si_shader_init_pm4_state(sscreen, shader);
 }
