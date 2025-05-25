--- sql/mysqld.cc.orig	2025-05-19 16:36:45 UTC
+++ sql/mysqld.cc
@@ -4680,8 +4680,9 @@ static void init_ssl()
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
