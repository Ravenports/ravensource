--- sql/mysqld.cc.orig	2024-10-29 14:32:34 UTC
+++ sql/mysqld.cc
@@ -4761,8 +4761,9 @@ static void init_ssl()
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
