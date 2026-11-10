--- lib/ortho/trapezoid.c.orig	2026-11-08 17:52:43 UTC
+++ lib/ortho/trapezoid.c
@@ -35,6 +35,11 @@
 #include <util/unreachable.h>
 #include <util/unused.h>
 
+#include <sys/param.h>
+#if __FreeBSD_version <= 704101 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2(x)  (log(x)/log(2))
+#endif
+
 /* Node types */
 
 #define T_X     1
