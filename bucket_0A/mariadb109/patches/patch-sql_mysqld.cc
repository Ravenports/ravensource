--- sql/mysqld.cc.orig	2023-02-01 16:51:58 UTC
+++ sql/mysqld.cc
@@ -4655,8 +4655,9 @@ static void init_ssl()
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
