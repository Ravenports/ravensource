--- sql/mysqld.cc.orig	2023-08-11 10:53:13 UTC
+++ sql/mysqld.cc
@@ -4732,8 +4732,9 @@ static void init_ssl()
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
