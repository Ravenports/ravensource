--- connectivity/source/drivers/mysqlc/mysqlc_preparedstatement.hxx.orig	2019-09-18 14:12:06 UTC
+++ connectivity/source/drivers/mysqlc/mysqlc_preparedstatement.hxx
@@ -39,11 +39,17 @@ using ::com::sun::star::uno::Reference;
 using ::com::sun::star::uno::RuntimeException;
 using ::com::sun::star::uno::Type;
 
+#if defined MYSQL_VERSION_ID && (MYSQL_VERSION_ID >= 80000) && !defined MARIADB_BASE_VERSION
+using my_bool = bool;
+#else
+using my_bool = char;
+#endif
+
 struct BindMetaData
 {
-    char is_null = 0;
+    my_bool is_null = 0;
     unsigned long length = 0;
-    char error = 0;
+    my_bool error = 0;
 };
 
 typedef ::cppu::ImplHelper5<css::sdbc::XPreparedStatement, css::sdbc::XParameters,
