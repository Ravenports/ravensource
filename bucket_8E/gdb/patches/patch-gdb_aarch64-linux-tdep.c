--- gdb/aarch64-linux-tdep.c.orig	2021-09-13 01:32:09 UTC
+++ gdb/aarch64-linux-tdep.c
@@ -1725,13 +1725,13 @@ aarch64_linux_report_signal_info (struct
     return;
 
   CORE_ADDR fault_addr = 0;
-  long si_code = 0;
+  long db_si_code = 0;
 
   try
     {
       /* Sigcode tells us if the segfault is actually a memory tag
 	 violation.  */
-      si_code = parse_and_eval_long ("$_siginfo.si_code");
+      db_si_code = parse_and_eval_long ("$_siginfo.si_code");
 
       fault_addr
 	= parse_and_eval_long ("$_siginfo._sifields._sigfault.si_addr");
@@ -1743,7 +1743,7 @@ aarch64_linux_report_signal_info (struct
     }
 
   /* If this is not a memory tag violation, just return.  */
-  if (si_code != SEGV_MTEAERR && si_code != SEGV_MTESERR)
+  if (db_si_code != SEGV_MTEAERR && db_si_code != SEGV_MTESERR)
     return;
 
   uiout->text ("\n");
@@ -1751,7 +1751,7 @@ aarch64_linux_report_signal_info (struct
   uiout->field_string ("sigcode-meaning", _("Memory tag violation"));
 
   /* For synchronous faults, show additional information.  */
-  if (si_code == SEGV_MTESERR)
+  if (db_si_code == SEGV_MTESERR)
     {
       uiout->text (_(" while accessing address "));
       uiout->field_core_addr ("fault-addr", gdbarch, fault_addr);
