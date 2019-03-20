--- src/gallium/drivers/radeonsi/si_state_shaders.c.orig	2019-03-18 15:52:18 UTC
+++ src/gallium/drivers/radeonsi/si_state_shaders.c
@@ -1720,6 +1720,7 @@ static void si_build_shader_variant(stru
 		return;
 	}
 
+#ifndef __sun__
 	if (shader->compiler_ctx_state.is_debug_context) {
 		FILE *f = open_memstream(&shader->shader_log,
 					 &shader->shader_log_size);
@@ -1728,6 +1729,7 @@ static void si_build_shader_variant(stru
 			fclose(f);
 		}
 	}
+#endif
 
 	si_shader_init_pm4_state(sscreen, shader);
 }
