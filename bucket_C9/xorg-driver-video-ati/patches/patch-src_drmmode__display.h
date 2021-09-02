--- src/drmmode_display.h.orig	2019-10-15 16:16:29 UTC
+++ src/drmmode_display.h
@@ -262,7 +262,7 @@ Bool drmmode_wait_vblank(xf86CrtcPtr crt
 			 uint64_t *ust, uint32_t *result_seq);
 
 
-miPointerSpriteFuncRec drmmode_sprite_funcs;
+extern miPointerSpriteFuncRec drmmode_sprite_funcs;
 
 
 #endif
