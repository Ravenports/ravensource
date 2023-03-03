--- sql/mysqld.cc.orig	2023-01-30 20:31:35 UTC
+++ sql/mysqld.cc
@@ -4453,8 +4453,9 @@ static void init_ssl()
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
