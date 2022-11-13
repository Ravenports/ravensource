--- sql/mysqld.cc.orig	2022-11-03 10:44:30 UTC
+++ sql/mysqld.cc
@@ -4667,8 +4667,9 @@ static void init_ssl()
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
