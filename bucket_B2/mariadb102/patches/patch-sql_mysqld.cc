--- sql/mysqld.cc.orig	2020-01-26 16:43:30 UTC
+++ sql/mysqld.cc
@@ -4918,8 +4918,9 @@ static void init_ssl()
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
