--- sql/mysqld.cc.orig	2025-05-19 16:14:25 UTC
+++ sql/mysqld.cc
@@ -4719,8 +4719,9 @@ static void init_ssl()
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
