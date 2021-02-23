--- sql/mysqld.cc.orig	2021-02-18 23:22:29 UTC
+++ sql/mysqld.cc
@@ -3261,7 +3261,11 @@ pthread_handler_t signal_hand(void *arg
       }
       break;
     case SIGHUP:
+#ifdef SI_KERNEL
       if (!abort_loop && origin != SI_KERNEL)
+#else
+      if (!abort_loop)
+#endif
       {
         int not_used;
 	mysql_print_status();		// Print some debug info
@@ -4727,8 +4731,9 @@ static void init_ssl()
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
