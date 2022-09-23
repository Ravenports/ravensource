--- sql/mysqld.cc.orig	2022-08-10 10:25:14 UTC
+++ sql/mysqld.cc
@@ -4768,8 +4768,9 @@ static void init_ssl()
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
