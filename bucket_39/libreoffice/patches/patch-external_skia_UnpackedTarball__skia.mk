--- external/skia/UnpackedTarball_skia.mk.orig	2023-04-27 20:06:32 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -41,6 +41,8 @@ skia_patches := \
     constexpr-template.patch.0 \
     missing-include.patch.0 \
     tdf147342.patch.0 \
+    gfx-skia-skia-src-core-SkCpu.cpp.patch.0 \
+    netbsd.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
