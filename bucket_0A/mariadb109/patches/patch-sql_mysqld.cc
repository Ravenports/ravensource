--- sql/mysqld.cc.orig	2022-09-13 19:14:39 UTC
+++ sql/mysqld.cc
@@ -4657,8 +4657,9 @@ static void init_ssl()
         sql_print_warning("SSL error: %s",buf);
       }
     }
-    else
+    else {
       ERR_remove_state(0);
+    }
   }
   else
   {
