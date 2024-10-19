--- external/libcmis/UnpackedTarball_libcmis.mk.orig	2024-09-23 13:53:35 UTC
+++ external/libcmis/UnpackedTarball_libcmis.mk
@@ -25,6 +25,7 @@ $(eval $(call gb_UnpackedTarball_add_pat
 	external/libcmis/0001-cppcheck-operatorEqVarError-in-src-libcmis-http-sess.patch \
 	external/libcmis/0001-Take-into-account-m_CurlInitProtocolsFunction-in-cop.patch \
 	external/libcmis/initprotocols.patch.1 \
+	external/libcmis/libcmis_xml-utils-2.patch \
 ))
 
 # vim: set noet sw=4 ts=4:
