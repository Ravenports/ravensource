--- gdb/i386-fbsd-nat.c.orig	2018-07-31 14:47:55 UTC
+++ gdb/i386-fbsd-nat.c
@@ -159,7 +159,6 @@ _initialize_i386fbsd_nat (void)
   t->to_read_description = i386fbsd_read_description;
 #endif
 
-  t->to_resume = i386fbsd_resume;
   fbsd_nat_add_target (t);
 
   /* Support debugging kernel virtual memory images.  */
