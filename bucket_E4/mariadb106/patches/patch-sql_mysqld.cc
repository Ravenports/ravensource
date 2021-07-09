--- sql/mysqld.cc.orig	2021-07-05 10:15:49 UTC
+++ sql/mysqld.cc
@@ -4562,8 +4562,9 @@ static void init_ssl()
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
