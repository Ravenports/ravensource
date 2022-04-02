--- sql/mysqld.cc.orig	2022-02-10 19:42:55 UTC
+++ sql/mysqld.cc
@@ -4731,8 +4731,9 @@ static void init_ssl()
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
