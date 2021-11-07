--- gdb/i386-bsd-nat.c.orig	2021-07-03 17:41:09 UTC
+++ gdb/i386-bsd-nat.c
@@ -356,6 +356,8 @@ _initialize_i386bsd_nat ()
 #define SC_REG_OFFSET i386fbsd_sc_reg_offset
 #elif defined (OpenBSD)
 #define SC_REG_OFFSET i386obsd_sc_reg_offset
+#elif defined (DragonFly)
+#define SC_REG_OFFSET i386dfly_sc_reg_offset
 #endif
 
 #ifdef SC_REG_OFFSET
