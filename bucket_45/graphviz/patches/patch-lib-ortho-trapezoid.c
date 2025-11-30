--- lib/ortho/trapezoid.c.orig	2025-11-29 02:59:10 UTC
+++ lib/ortho/trapezoid.c
@@ -34,6 +34,11 @@
 #include <util/list.h>
 #include <util/unreachable.h>
 
+#include <sys/param.h>
+#if __FreeBSD_version <= 704101 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2(x)  (log(x)/log(2))
+#endif
+
 /* Node types */
 
 #define T_X     1
