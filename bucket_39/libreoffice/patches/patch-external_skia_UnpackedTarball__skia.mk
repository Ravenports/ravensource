--- external/skia/UnpackedTarball_skia.mk.orig	2022-11-16 17:29:15 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -38,6 +38,7 @@ skia_patches := \
     allow-no-es2restrictions.patch.1 \
     vk_mem_alloc.patch.1 \
     tdf148624.patch.1 \
+    netbsd.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
