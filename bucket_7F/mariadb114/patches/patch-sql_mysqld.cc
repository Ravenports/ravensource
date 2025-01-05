--- sql/mysqld.cc.orig	2024-10-30 14:38:16 UTC
+++ sql/mysqld.cc
@@ -4694,8 +4694,9 @@ static void init_ssl()
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
