--- sql/mysqld.cc.orig	2026-01-27 21:45:34.000000000 -0000
+++ sql/mysqld.cc
@@ -4603,8 +4603,9 @@ static void init_ssl()
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
