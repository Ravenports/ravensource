--- sql/mysqld.cc.orig	2021-05-05 15:26:23 UTC
+++ sql/mysqld.cc
@@ -5033,8 +5033,9 @@ static void init_ssl()
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
