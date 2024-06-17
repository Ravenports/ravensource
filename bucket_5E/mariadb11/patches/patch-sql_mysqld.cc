--- sql/mysqld.cc.orig	2024-05-26 18:15:38 UTC
+++ sql/mysqld.cc
@@ -4658,8 +4658,9 @@ static void init_ssl()
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
