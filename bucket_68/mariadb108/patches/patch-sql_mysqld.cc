--- sql/mysqld.cc.orig	2022-09-13 07:09:53 UTC
+++ sql/mysqld.cc
@@ -4656,8 +4656,9 @@ static void init_ssl()
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
