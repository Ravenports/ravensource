--- sql/mysqld.cc.orig	2023-02-01 17:30:48 UTC
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
