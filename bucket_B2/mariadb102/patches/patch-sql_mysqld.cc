--- sql/mysqld.cc.orig	2021-11-05 18:07:43 UTC
+++ sql/mysqld.cc
@@ -4972,8 +4972,9 @@ static void init_ssl()
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
