--- external/libcmis/UnpackedTarball_libcmis.mk.orig	2024-07-10 15:12:43 UTC
+++ external/libcmis/UnpackedTarball_libcmis.mk
@@ -15,6 +15,7 @@ $(eval $(call gb_UnpackedTarball_set_pat
 
 $(eval $(call gb_UnpackedTarball_add_patches,libcmis,\
 	external/libcmis/http-session-cleanup.patch.1 \
+	external/libcmis/libcmis_xml-utils.patch \
 ))
 
 # vim: set noet sw=4 ts=4:
