--- sql/mysqld.cc.orig	2021-05-05 20:10:09 UTC
+++ sql/mysqld.cc
@@ -4725,8 +4725,9 @@ static void init_ssl()
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
