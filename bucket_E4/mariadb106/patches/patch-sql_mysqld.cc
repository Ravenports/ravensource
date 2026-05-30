--- sql/mysqld.cc.orig	2026-05-23 14:56:59 UTC
+++ sql/mysqld.cc
@@ -4613,8 +4613,9 @@ static void init_ssl()
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
