--- sql/mysqld.cc.orig	2020-01-26 20:43:53 UTC
+++ sql/mysqld.cc
@@ -3282,7 +3282,11 @@ pthread_handler_t signal_hand(void *arg
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
@@ -4736,8 +4740,9 @@ static void init_ssl()
       while ((err= ERR_get_error()))
         sql_print_warning("SSL error: %s", ERR_error_string(err, NULL));
     }
-    else
+    else {
       ERR_remove_state(0);
+    }
   }
   else
   {
