--- src/sna/sna_accel.c.orig	2025-03-21 21:10:23 UTC
+++ src/sna/sna_accel.c
@@ -8912,7 +8912,7 @@ sna_copy_plane(DrawablePtr src, Drawable
 		}
 
 		if (!kgem_bo_can_blt(&sna->kgem, arg.bo))
-			return false;
+			return NULL;
 
 		RegionUninit(&region);
 		return sna_do_copy(src, dst, gc,
