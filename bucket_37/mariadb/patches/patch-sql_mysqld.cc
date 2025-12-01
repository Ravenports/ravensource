--- sql/mysqld.cc.orig	2025-11-13 17:00:49 UTC
+++ sql/mysqld.cc
@@ -4770,8 +4770,9 @@ static void init_ssl()
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
