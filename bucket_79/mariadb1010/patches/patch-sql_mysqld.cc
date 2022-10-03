--- sql/mysqld.cc.orig	2022-08-10 13:36:04 UTC
+++ sql/mysqld.cc
@@ -4648,8 +4648,9 @@ static void init_ssl()
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
