--- src/sna/sna_accel.c.orig	2023-02-01 18:07:58 UTC
+++ src/sna/sna_accel.c
@@ -8912,7 +8912,7 @@ sna_copy_plane(DrawablePtr src, Drawable
 		}
 
 		if (!kgem_bo_can_blt(&sna->kgem, arg.bo))
-			return false;
+			return NULL;
 
 		RegionUninit(&region);
 		return sna_do_copy(src, dst, gc,
