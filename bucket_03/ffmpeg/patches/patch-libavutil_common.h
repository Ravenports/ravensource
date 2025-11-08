--- libavutil/common.h.orig	2025-08-22 09:24:19 UTC
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
