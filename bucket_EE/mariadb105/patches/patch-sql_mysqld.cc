--- sql/mysqld.cc.orig	2024-05-08 18:05:54 UTC
+++ sql/mysqld.cc
@@ -4473,8 +4473,9 @@ static void init_ssl()
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
