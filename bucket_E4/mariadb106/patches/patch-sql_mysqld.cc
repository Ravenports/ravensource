--- sql/mysqld.cc.orig	2025-07-28 15:52:27 UTC
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
