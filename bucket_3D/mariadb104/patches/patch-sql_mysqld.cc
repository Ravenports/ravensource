--- sql/mysqld.cc.orig	2023-05-05 08:22:35 UTC
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
