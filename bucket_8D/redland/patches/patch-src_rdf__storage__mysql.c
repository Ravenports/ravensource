--- src/rdf_storage_mysql.c.orig	2012-12-29 23:01:17 UTC
+++ src/rdf_storage_mysql.c
@@ -447,7 +447,11 @@ librdf_storage_mysql_get_handle(librdf_s
 
 #ifdef HAVE_MYSQL_OPT_RECONNECT
   if(1) {
+#if MYSQL_VERSION_ID > 80000
+    bool value=(context->reconnect) ? 1 : 0;
+#else
     my_bool value=(context->reconnect) ? 1 : 0;
+#endif
     mysql_options(connection->handle, MYSQL_OPT_RECONNECT, &value);
   }
 #endif
