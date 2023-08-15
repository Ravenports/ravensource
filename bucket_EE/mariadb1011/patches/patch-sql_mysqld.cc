--- sql/mysqld.cc.orig	2023-08-11 06:39:42 UTC
+++ sql/mysqld.cc
@@ -4729,8 +4729,9 @@ static void init_ssl()
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
