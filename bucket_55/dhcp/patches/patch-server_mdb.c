--- server/mdb.c.orig	2021-05-14 10:51:30 UTC
+++ server/mdb.c
@@ -67,7 +67,7 @@ static host_id_info_t *host_id_info = NU
 
 int numclasseswritten;
 
-omapi_object_type_t *dhcp_type_host;
+extern omapi_object_type_t *dhcp_type_host;
 
 isc_result_t enter_class(cd, dynamicp, commit)
 	struct class *cd;
