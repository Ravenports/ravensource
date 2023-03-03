--- sql/mysqld.cc.orig	2023-02-01 15:03:31 UTC
+++ sql/mysqld.cc
@@ -4617,8 +4617,9 @@ static void init_ssl()
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
