--- sql/mysqld.cc.orig	2023-05-05 11:04:36 UTC
+++ sql/mysqld.cc
@@ -4615,8 +4615,9 @@ static void init_ssl()
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
