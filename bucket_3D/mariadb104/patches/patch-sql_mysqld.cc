--- sql/mysqld.cc.orig	2024-05-06 15:18:46 UTC
+++ sql/mysqld.cc
@@ -4787,8 +4787,9 @@ static void init_ssl()
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
