--- sql/mysqld.cc.orig	2025-11-13 08:45:31 UTC
+++ sql/mysqld.cc
@@ -4766,8 +4766,9 @@ static void init_ssl()
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
