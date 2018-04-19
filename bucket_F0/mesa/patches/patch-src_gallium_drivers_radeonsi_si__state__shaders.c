--- src/gallium/drivers/radeonsi/si_state_shaders.c.orig	2018-04-18 14:47:54 UTC
+++ src/gallium/drivers/radeonsi/si_state_shaders.c
@@ -1463,6 +1463,7 @@ static void si_build_shader_variant(stru
 		return;
 	}
 
+#ifndef __sun__
 	if (shader->compiler_ctx_state.is_debug_context) {
 		FILE *f = open_memstream(&shader->shader_log,
 					 &shader->shader_log_size);
@@ -1471,6 +1472,7 @@ static void si_build_shader_variant(stru
 			fclose(f);
 		}
 	}
+#endif
 
 	si_shader_init_pm4_state(sscreen, shader);
 }
