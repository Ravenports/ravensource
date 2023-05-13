--- sql/mysqld.cc.orig	2023-05-05 13:40:23 UTC
+++ sql/mysqld.cc
@@ -4717,8 +4717,9 @@ static void init_ssl()
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
