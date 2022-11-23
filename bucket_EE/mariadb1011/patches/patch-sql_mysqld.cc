--- sql/mysqld.cc.orig	2022-11-14 18:13:56 UTC
+++ sql/mysqld.cc
@@ -4732,8 +4732,9 @@ static void init_ssl()
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
