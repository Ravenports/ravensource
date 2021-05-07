--- sql/mysqld.cc.orig	2021-05-05 21:00:19 UTC
+++ sql/mysqld.cc
@@ -4407,8 +4407,9 @@ static void init_ssl()
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
