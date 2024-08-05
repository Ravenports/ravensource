--- libavutil/common.h.orig	2024-08-02 22:55:22 UTC
+++ libavutil/common.h
@@ -50,6 +50,10 @@
 #   include "internal.h"
 #endif /* HAVE_AV_CONFIG_H */
 
+#ifndef	UINT64_C
+#define	UINT64_C(c)	(c ## UL)
+#endif
+
 //rounded division & shift
 #define RSHIFT(a,b) ((a) > 0 ? ((a) + ((1<<(b))>>1))>>(b) : ((a) + ((1<<(b))>>1)-1)>>(b))
 /* assume b>0 */
