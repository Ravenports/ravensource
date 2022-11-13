--- sql/mysqld.cc.orig	2022-11-03 10:07:24 UTC
+++ sql/mysqld.cc
@@ -4630,8 +4630,9 @@ static void init_ssl()
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
