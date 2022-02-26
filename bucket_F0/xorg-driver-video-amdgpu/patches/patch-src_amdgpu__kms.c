--- src/amdgpu_kms.c.orig	2021-07-30 13:44:22 UTC
+++ src/amdgpu_kms.c
@@ -931,7 +931,7 @@ static void
 amdgpu_dirty_update(ScrnInfoPtr scrn)
 {
 	ScreenPtr screen = scrn->pScreen;
-	PixmapDirtyUpdatePtr ent;
+	PixmapDirtyUpdatePtr ent = NULL;
 	RegionPtr region;
 
 	xorg_list_for_each_entry(ent, &screen->pixmap_dirty_list, ent) {
