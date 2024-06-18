--- external/libcmis/UnpackedTarball_libcmis.mk.orig	2024-04-29 18:46:10 UTC
+++ external/libcmis/UnpackedTarball_libcmis.mk
@@ -13,7 +13,11 @@ $(eval $(call gb_UnpackedTarball_set_tar
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,libcmis,1))
 
+libcmis_patches := \
+	libcmis_xml-utils.patch
+
 $(eval $(call gb_UnpackedTarball_add_patches,libcmis,\
+   $(foreach patch,$(libcmis_patches),external/libcmis/$(patch)) \
 ))
 
 # vim: set noet sw=4 ts=4:
