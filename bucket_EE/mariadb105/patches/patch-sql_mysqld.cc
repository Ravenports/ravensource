--- sql/mysqld.cc.orig	2022-02-10 20:11:32 UTC
+++ sql/mysqld.cc
@@ -4413,8 +4413,9 @@ static void init_ssl()
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
