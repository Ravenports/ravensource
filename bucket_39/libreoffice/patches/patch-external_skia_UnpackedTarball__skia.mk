--- external/skia/UnpackedTarball_skia.mk.orig	2023-01-12 21:06:06 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -40,6 +40,7 @@ skia_patches := \
     tdf148624.patch.1 \
     constexpr-template.patch.0 \
     missing-include.patch.0 \
+    netbsd.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
