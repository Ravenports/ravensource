--- sql/mysqld.cc.orig	2026-09-10 13:53:25 UTC
+++ sql/mysqld.cc
@@ -502,7 +502,7 @@ READ_ONLY_SYSVAR char* opt_secure_file_p
 READ_ONLY_SYSVAR my_bool lower_case_file_system;
 READ_ONLY_SYSVAR my_bool opt_large_pages;
 #ifdef HAVE_SOLARIS_LARGE_PAGES
-my_bool opt_super_large_pages= 0;
+extern my_bool opt_super_large_pages;
 #endif
 my_bool opt_myisam_use_mmap= 0;
 #if defined(ENABLED_DEBUG_SYNC)
@@ -4926,8 +4926,9 @@ static void init_ssl()
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
