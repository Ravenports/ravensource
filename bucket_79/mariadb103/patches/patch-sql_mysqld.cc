--- sql/mysqld.cc.orig	2022-02-10 19:31:00 UTC
+++ sql/mysqld.cc
@@ -5035,8 +5035,9 @@ static void init_ssl()
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
