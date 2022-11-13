--- sql/mysqld.cc.orig	2022-09-23 14:41:20 UTC
+++ sql/mysqld.cc
@@ -4649,8 +4649,9 @@ static void init_ssl()
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
