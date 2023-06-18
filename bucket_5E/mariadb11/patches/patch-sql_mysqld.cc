--- sql/mysqld.cc.orig	2023-06-05 17:36:14 UTC
+++ sql/mysqld.cc
@@ -4720,8 +4720,9 @@ static void init_ssl()
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
