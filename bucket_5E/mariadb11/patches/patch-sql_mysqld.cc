--- sql/mysqld.cc.orig	2024-11-11 07:18:44 UTC
+++ sql/mysqld.cc
@@ -4778,8 +4778,9 @@ static void init_ssl()
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
