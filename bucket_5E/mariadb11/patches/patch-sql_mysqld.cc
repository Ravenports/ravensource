--- sql/mysqld.cc.orig	2025-05-21 14:08:47 UTC
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
