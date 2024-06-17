--- sql/mysqld.cc.orig	2024-05-10 21:02:49 UTC
+++ sql/mysqld.cc
@@ -4730,8 +4730,9 @@ static void init_ssl()
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
