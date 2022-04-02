--- sql/mysqld.cc.orig	2022-02-10 18:06:19 UTC
+++ sql/mysqld.cc
@@ -4974,8 +4974,9 @@ static void init_ssl()
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
