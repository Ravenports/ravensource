--- src/gallium/drivers/radeonsi/si_state_shaders.c.orig	2019-11-06 16:53:31 UTC
+++ src/gallium/drivers/radeonsi/si_state_shaders.c
@@ -2112,6 +2112,7 @@ static void si_build_shader_variant(stru
 		return;
 	}
 
+#ifndef __sun__
 	if (shader->compiler_ctx_state.is_debug_context) {
 		FILE *f = open_memstream(&shader->shader_log,
 					 &shader->shader_log_size);
@@ -2120,6 +2121,7 @@ static void si_build_shader_variant(stru
 			fclose(f);
 		}
 	}
+#endif
 
 	si_shader_init_pm4_state(sscreen, shader);
 }
