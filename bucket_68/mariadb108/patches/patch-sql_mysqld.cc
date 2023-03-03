--- sql/mysqld.cc.orig	2023-02-01 16:25:53 UTC
+++ sql/mysqld.cc
@@ -4654,8 +4654,9 @@ static void init_ssl()
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
