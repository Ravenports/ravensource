--- sql/mysqld.cc.orig	2020-11-09 21:59:49 UTC
+++ sql/mysqld.cc
@@ -4977,8 +4977,9 @@ static void init_ssl()
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
