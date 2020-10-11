--- sql/mysqld.cc.orig	2020-10-05 16:06:27 UTC
+++ sql/mysqld.cc
@@ -4928,8 +4928,9 @@ static void init_ssl()
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
