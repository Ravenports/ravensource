--- sql/mysqld.cc.orig	2023-11-19 07:41:57 UTC
+++ sql/mysqld.cc
@@ -4759,8 +4759,9 @@ static void init_ssl()
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
