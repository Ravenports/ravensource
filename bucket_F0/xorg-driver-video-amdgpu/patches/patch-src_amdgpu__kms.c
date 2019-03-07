--- src/amdgpu_kms.c.orig	2019-03-06 11:42:30 UTC
+++ src/amdgpu_kms.c
@@ -930,7 +930,7 @@ static void
 amdgpu_dirty_update(ScrnInfoPtr scrn)
 {
 	ScreenPtr screen = scrn->pScreen;
-	PixmapDirtyUpdatePtr ent;
+	PixmapDirtyUpdatePtr ent = NULL;
 	RegionPtr region;
 
 	xorg_list_for_each_entry(ent, &screen->pixmap_dirty_list, ent) {
