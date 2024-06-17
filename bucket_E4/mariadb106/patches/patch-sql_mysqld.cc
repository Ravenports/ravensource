--- sql/mysqld.cc.orig	2024-05-09 08:56:46 UTC
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
