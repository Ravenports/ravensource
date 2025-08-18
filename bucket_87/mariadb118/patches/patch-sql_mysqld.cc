--- sql/mysqld.cc.orig	2025-07-28 19:35:05 UTC
+++ sql/mysqld.cc
@@ -4765,8 +4765,9 @@ static void init_ssl()
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
