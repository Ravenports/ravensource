--- sql/mysqld.cc.orig	2026-11-17 07:14:00 UTC
+++ sql/mysqld.cc
@@ -509,7 +509,7 @@ READ_ONLY_SYSVAR my_bool master_ssl_veri
 READ_ONLY_SYSVAR my_bool master_use_gtid_is_auto;
 
 #ifdef HAVE_SOLARIS_LARGE_PAGES
-my_bool opt_super_large_pages= 0;
+extern my_bool opt_super_large_pages;
 #endif
 my_bool opt_myisam_use_mmap= 0;
 #if defined(ENABLED_DEBUG_SYNC)
@@ -4988,8 +4988,9 @@ static void init_ssl()
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
