--- sql/mysqld.cc.orig	2022-05-18 11:19:09 UTC
+++ sql/mysqld.cc
@@ -4979,8 +4979,9 @@ static void init_ssl()
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
