--- sql/mysqld.cc.orig	2024-10-29 13:25:01 UTC
+++ sql/mysqld.cc
@@ -4647,8 +4647,9 @@ static void init_ssl()
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
