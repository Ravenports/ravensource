--- sql/mysqld.cc.orig	2024-10-29 10:48:50 UTC
+++ sql/mysqld.cc
@@ -4490,8 +4490,9 @@ static void init_ssl()
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
