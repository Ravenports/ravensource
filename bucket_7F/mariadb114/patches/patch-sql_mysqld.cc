--- sql/mysqld.cc.orig	2026-01-31 10:50:14 UTC
+++ sql/mysqld.cc
@@ -4682,8 +4682,9 @@ static void init_ssl()
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
