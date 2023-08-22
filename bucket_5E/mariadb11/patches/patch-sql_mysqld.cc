--- sql/mysqld.cc.orig	2023-08-17 15:25:33 UTC
+++ sql/mysqld.cc
@@ -4735,8 +4735,9 @@ static void init_ssl()
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
