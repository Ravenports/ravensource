--- sql/mysqld.cc.orig	2022-08-10 10:53:22 UTC
+++ sql/mysqld.cc
@@ -4449,8 +4449,9 @@ static void init_ssl()
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
