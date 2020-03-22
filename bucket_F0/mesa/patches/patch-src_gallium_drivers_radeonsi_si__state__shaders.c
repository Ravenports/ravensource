--- src/gallium/drivers/radeonsi/si_state_shaders.c.orig	2020-03-18 21:24:19 UTC
+++ src/gallium/drivers/radeonsi/si_state_shaders.c
@@ -2207,6 +2207,7 @@ static void si_build_shader_variant(stru
 		return;
 	}
 
+#ifndef __sun__
 	if (shader->compiler_ctx_state.is_debug_context) {
 		FILE *f = open_memstream(&shader->shader_log,
 					 &shader->shader_log_size);
@@ -2215,6 +2216,7 @@ static void si_build_shader_variant(stru
 			fclose(f);
 		}
 	}
+#endif
 
 	si_shader_init_pm4_state(sscreen, shader);
 }
