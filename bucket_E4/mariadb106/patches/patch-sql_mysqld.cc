--- sql/mysqld.cc.orig	2021-11-05 20:03:30 UTC
+++ sql/mysqld.cc
@@ -4564,8 +4564,9 @@ static void init_ssl()
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
