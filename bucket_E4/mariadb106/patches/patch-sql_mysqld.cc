--- sql/mysqld.cc.orig	2025-04-27 06:05:50 UTC
+++ sql/mysqld.cc
@@ -4603,8 +4603,9 @@ static void init_ssl()
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
