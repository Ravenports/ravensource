--- sql/mysqld.cc.orig	2020-11-01 01:03:45 UTC
+++ sql/mysqld.cc
@@ -5038,8 +5038,9 @@ static void init_ssl()
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
