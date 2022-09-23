--- sql/mysqld.cc.orig	2022-09-13 06:00:23 UTC
+++ sql/mysqld.cc
@@ -4619,8 +4619,9 @@ static void init_ssl()
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
