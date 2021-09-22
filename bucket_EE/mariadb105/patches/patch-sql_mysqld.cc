--- sql/mysqld.cc.orig	2021-08-03 08:29:08 UTC
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
