--- sql/mysqld.cc.orig	2020-05-09 22:11:44 UTC
+++ sql/mysqld.cc
@@ -4986,8 +4986,9 @@ static void init_ssl()
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
