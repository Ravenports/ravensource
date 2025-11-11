--- sql/mysqld.cc.orig	2025-11-04 12:57:50 UTC
+++ sql/mysqld.cc
@@ -4681,8 +4681,9 @@ static void init_ssl()
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
