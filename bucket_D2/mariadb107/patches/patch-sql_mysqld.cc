--- sql/mysqld.cc.orig	2022-09-13 06:32:00 UTC
+++ sql/mysqld.cc
@@ -4651,8 +4651,9 @@ static void init_ssl()
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
