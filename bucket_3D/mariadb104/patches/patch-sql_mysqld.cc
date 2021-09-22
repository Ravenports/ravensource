--- sql/mysqld.cc.orig	2021-08-02 18:07:03 UTC
+++ sql/mysqld.cc
@@ -4728,8 +4728,9 @@ static void init_ssl()
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
