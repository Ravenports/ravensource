--- sql/mysqld.cc.orig	2023-08-10 20:16:54 UTC
+++ sql/mysqld.cc
@@ -4621,8 +4621,9 @@ static void init_ssl()
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
