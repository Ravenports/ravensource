--- src/amdgpu_kms.c.orig	2018-03-02 17:31:02 UTC
+++ src/amdgpu_kms.c
@@ -756,7 +756,7 @@ static void
 amdgpu_dirty_update(ScrnInfoPtr scrn)
 {
 	ScreenPtr screen = scrn->pScreen;
-	PixmapDirtyUpdatePtr ent;
+	PixmapDirtyUpdatePtr ent = NULL;
 	RegionPtr region;
 
 	xorg_list_for_each_entry(ent, &screen->pixmap_dirty_list, ent) {
