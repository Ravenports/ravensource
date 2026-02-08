--- sql/mysqld.cc.orig	2026-01-31 10:47:55 UTC
+++ sql/mysqld.cc
@@ -4720,8 +4720,9 @@ static void init_ssl()
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
