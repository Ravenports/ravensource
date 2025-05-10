--- sql/mysqld.cc.orig	2025-04-25 16:21:42 UTC
+++ sql/mysqld.cc
@@ -4446,8 +4446,9 @@ static void init_ssl()
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
