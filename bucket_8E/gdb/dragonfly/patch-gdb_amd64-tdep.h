--- gdb/amd64-tdep.h.orig	2020-05-23 21:10:29 UTC
+++ gdb/amd64-tdep.h
@@ -145,8 +145,8 @@ extern int amd64nbsd_r_reg_offset[];
 extern int amd64obsd_r_reg_offset[];
 
 /* Variables exported from amd64-fbsd-tdep.c.  */
-extern CORE_ADDR amd64fbsd_sigtramp_start_addr;
-extern CORE_ADDR amd64fbsd_sigtramp_end_addr;
-extern int amd64fbsd_sc_reg_offset[];
+extern CORE_ADDR amd64dfly_sigtramp_start_addr;
+extern CORE_ADDR amd64dfly_sigtramp_end_addr;
+extern int amd64dfly_sc_reg_offset[];
 
 #endif /* amd64-tdep.h */
