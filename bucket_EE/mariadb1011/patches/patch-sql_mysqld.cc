--- sql/mysqld.cc.orig	2025-07-28 16:12:32 UTC
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
