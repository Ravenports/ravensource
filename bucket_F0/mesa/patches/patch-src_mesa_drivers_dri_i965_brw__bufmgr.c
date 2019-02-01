--- src/mesa/drivers/dri/i965/brw_bufmgr.c.orig	2019-01-31 21:05:07 UTC
+++ src/mesa/drivers/dri/i965/brw_bufmgr.c
@@ -77,6 +77,10 @@
 #define VG(x)
 #endif
 
+#ifndef O_CLOEXEC
+#define O_CLOEXEC	0
+#endif
+
 /* VALGRIND_FREELIKE_BLOCK unfortunately does not actually undo the earlier
  * VALGRIND_MALLOCLIKE_BLOCK but instead leaves vg convinced the memory is
  * leaked. All because it does not call VG(cli_free) from its
