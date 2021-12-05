--- lib/ortho/trapezoid.c.orig	2021-12-04 20:07:22 UTC
+++ lib/ortho/trapezoid.c
@@ -22,6 +22,11 @@
 #include <common/types.h>
 #include <ortho/trap.h>
 
+#include <sys/param.h>
+#if __FreeBSD_version <= 704101 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2(x)  (log(x)/log(2))
+#endif
+
 /* Node types */
 
 #define T_X     1
