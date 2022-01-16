--- sql/mysqld.cc.orig	2021-11-05 20:29:29 UTC
+++ sql/mysqld.cc
@@ -4597,8 +4597,9 @@ static void init_ssl()
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
