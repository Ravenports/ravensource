--- sql/mysqld.cc.orig	2020-05-08 11:45:23 UTC
+++ sql/mysqld.cc
@@ -4925,8 +4925,9 @@ static void init_ssl()
       while ((err= ERR_get_error()))
         sql_print_warning("SSL error: %s", ERR_error_string(err, NULL));
     }
-    else
+    else {
       ERR_remove_state(0);
+    }
   }
   else
   {
