--- gdb/i386-bsd-nat.c.orig	2020-10-24 04:23:02 UTC
+++ gdb/i386-bsd-nat.c
@@ -360,6 +360,8 @@ _initialize_i386bsd_nat ()
 #define SC_REG_OFFSET i386nbsd_sc_reg_offset
 #elif defined (OpenBSD)
 #define SC_REG_OFFSET i386obsd_sc_reg_offset
+#elif defined (DragonFly)
+#define SC_REG_OFFSET i386dfly_sc_reg_offset
 #endif
 
 #ifdef SC_REG_OFFSET
