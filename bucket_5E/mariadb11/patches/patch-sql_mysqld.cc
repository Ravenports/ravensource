--- sql/mysqld.cc.orig	2023-11-08 17:11:50 UTC
+++ sql/mysqld.cc
@@ -4740,8 +4740,9 @@ static void init_ssl()
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
