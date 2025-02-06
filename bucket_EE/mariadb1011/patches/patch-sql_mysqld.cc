--- sql/mysqld.cc.orig	2025-01-30 11:01:24 UTC
+++ sql/mysqld.cc
@@ -4717,8 +4717,9 @@ static void init_ssl()
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
