--- sql/mysqld.cc.orig	2024-01-31 16:38:21 UTC
+++ sql/mysqld.cc
@@ -4461,8 +4461,9 @@ static void init_ssl()
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
