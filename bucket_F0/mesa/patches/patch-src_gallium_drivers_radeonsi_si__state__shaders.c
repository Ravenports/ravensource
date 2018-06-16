--- src/gallium/drivers/radeonsi/si_state_shaders.c.orig	2018-06-15 20:37:48 UTC
+++ src/gallium/drivers/radeonsi/si_state_shaders.c
@@ -1515,6 +1515,7 @@ static void si_build_shader_variant(stru
 		return;
 	}
 
+#ifndef __sun__
 	if (shader->compiler_ctx_state.is_debug_context) {
 		FILE *f = open_memstream(&shader->shader_log,
 					 &shader->shader_log_size);
@@ -1523,6 +1524,7 @@ static void si_build_shader_variant(stru
 			fclose(f);
 		}
 	}
+#endif
 
 	si_shader_init_pm4_state(sscreen, shader);
 }
