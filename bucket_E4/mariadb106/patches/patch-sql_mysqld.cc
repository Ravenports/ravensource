--- sql/mysqld.cc.orig	2023-06-05 17:02:21 UTC
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
