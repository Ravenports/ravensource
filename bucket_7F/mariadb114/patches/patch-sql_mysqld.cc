--- sql/mysqld.cc.orig	2025-01-30 17:54:55 UTC
+++ sql/mysqld.cc
@@ -4677,8 +4677,9 @@ static void init_ssl()
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
