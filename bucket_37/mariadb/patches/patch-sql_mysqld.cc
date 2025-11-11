--- sql/mysqld.cc.orig	2025-07-31 19:06:52 UTC
+++ sql/mysqld.cc
@@ -4769,8 +4769,9 @@ static void init_ssl()
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
