--- sql/mysqld.cc.orig	2022-11-02 12:18:50 UTC
+++ sql/mysqld.cc
@@ -4780,8 +4780,9 @@ static void init_ssl()
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
