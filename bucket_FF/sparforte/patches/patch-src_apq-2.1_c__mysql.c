--- src/apq-2.1/c_mysql.c.orig	2020-04-11 19:42:18 UTC
+++ src/apq-2.1/c_mysql.c
@@ -21,10 +21,10 @@
  */
 
 #include <stdio.h>
+#include <mysql_version.h>
+#if MYSQL_VERSION_ID < 80000
 #include <my_global.h>
 #include <my_sys.h>
-#ifdef _WINDOWS
-#include <my_global.h>
 #endif
 #include <mysql.h>
 #include <errmsg.h>
@@ -326,7 +326,11 @@ c_mysql_free_result(MYSQL_RES *result) {
 
 EXPORT void
 c_my_init(void) {
+#if MYSQL_VERSION_ID < 80000
 	my_init();
+#else
+	return;
+#endif
 }
 
 EXPORT my_ulonglong
