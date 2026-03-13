--- sql/mysqld.cc.orig	2026-01-31 13:27:48 UTC
+++ sql/mysqld.cc
@@ -430,7 +430,7 @@ char* opt_secure_file_priv;
 my_bool lower_case_file_system= 0;
 my_bool opt_large_pages= 0;
 #ifdef HAVE_SOLARIS_LARGE_PAGES
-my_bool opt_super_large_pages= 0;
+extern my_bool opt_super_large_pages;
 #endif
 my_bool opt_myisam_use_mmap= 0;
 uint   opt_large_page_size= 0;
@@ -4767,8 +4767,9 @@ static void init_ssl()
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
