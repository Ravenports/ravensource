--- sql/mysqld.cc.orig	2023-01-28 13:25:27 UTC
+++ sql/mysqld.cc
@@ -5034,8 +5034,9 @@ static void init_ssl()
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
