--- sql/mysqld.cc.orig	2022-02-10 20:33:06 UTC
+++ sql/mysqld.cc
@@ -4600,8 +4600,9 @@ static void init_ssl()
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
