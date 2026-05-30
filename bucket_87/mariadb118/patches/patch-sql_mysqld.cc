--- sql/mysqld.cc.orig	2026-05-24 09:58:32 UTC
+++ sql/mysqld.cc
@@ -432,7 +432,7 @@ char* opt_secure_file_priv;
 my_bool lower_case_file_system= 0;
 my_bool opt_large_pages= 0;
 #ifdef HAVE_SOLARIS_LARGE_PAGES
-my_bool opt_super_large_pages= 0;
+extern my_bool opt_super_large_pages;
 #endif
 my_bool opt_myisam_use_mmap= 0;
 uint   opt_large_page_size= 0;
@@ -4834,8 +4834,9 @@ static void init_ssl()
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
