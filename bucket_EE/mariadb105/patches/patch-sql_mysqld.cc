--- sql/mysqld.cc.orig	2021-11-05 19:40:06 UTC
+++ sql/mysqld.cc
@@ -4410,8 +4410,9 @@ static void init_ssl()
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
