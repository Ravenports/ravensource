--- sql/mysqld.cc.orig	2025-02-11 19:05:57 UTC
+++ sql/mysqld.cc
@@ -4760,8 +4760,9 @@ static void init_ssl()
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
