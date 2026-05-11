--- libavutil/common.h.orig	2026-03-16 18:13:05 UTC
+++ libavutil/common.h
@@ -52,6 +52,10 @@
 #   include "mem.h"
 #endif /* HAVE_AV_CONFIG_H */
 
+#ifndef	UINT64_C
+#define	UINT64_C(c)	(c ## UL)
+#endif
+
 //rounded division & shift
 #define RSHIFT(a,b) ((a) > 0 ? ((a) + ((1<<(b))>>1))>>(b) : ((a) + ((1<<(b))>>1)-1)>>(b))
 /* assume b>0 */
