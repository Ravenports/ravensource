--- sql/mysqld.cc.orig	2025-07-28 18:18:15 UTC
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
