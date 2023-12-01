--- external/libcmis/UnpackedTarball_libcmis.mk.orig	2023-09-22 19:07:01 UTC
+++ external/libcmis/UnpackedTarball_libcmis.mk
@@ -20,6 +20,7 @@ $(eval $(call gb_UnpackedTarball_add_pat
 	external/libcmis/libcmis_oauth_pw_as_refreshtoken.patch.1 \
 	external/libcmis/libcmis_gdrive.patch.1 \
 	external/libcmis/libcmis-boost-string.patch \
+	external/libcmis/patch-lib_libcmis_xml-utils.hxx \
 ))
 
 # vim: set noet sw=4 ts=4:
