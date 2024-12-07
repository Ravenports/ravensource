--- lib/ortho/trapezoid.c.orig	2024-12-06 23:53:25 UTC
+++ lib/ortho/trapezoid.c
@@ -28,6 +28,11 @@
 #include <ortho/trap.h>
 #include <util/alloc.h>
 
+#include <sys/param.h>
+#if __FreeBSD_version <= 704101 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2(x)  (log(x)/log(2))
+#endif
+
 /* Node types */
 
 #define T_X     1
