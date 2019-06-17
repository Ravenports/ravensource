--- src/gallium/drivers/radeonsi/si_state_shaders.c.orig	2019-06-05 23:33:05 UTC
+++ src/gallium/drivers/radeonsi/si_state_shaders.c
@@ -1715,6 +1715,7 @@ static void si_build_shader_variant(stru
 		return;
 	}
 
+#ifndef __sun__
 	if (shader->compiler_ctx_state.is_debug_context) {
 		FILE *f = open_memstream(&shader->shader_log,
 					 &shader->shader_log_size);
@@ -1723,6 +1724,7 @@ static void si_build_shader_variant(stru
 			fclose(f);
 		}
 	}
+#endif
 
 	si_shader_init_pm4_state(sscreen, shader);
 }
