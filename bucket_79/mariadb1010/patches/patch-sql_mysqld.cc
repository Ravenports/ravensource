--- sql/mysqld.cc.orig	2022-11-14 18:12:13 UTC
+++ sql/mysqld.cc
@@ -4670,8 +4670,9 @@ static void init_ssl()
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
