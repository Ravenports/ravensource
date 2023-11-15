--- libavutil/common.h.orig	2023-11-09 23:38:51 UTC
+++ libavutil/common.h
@@ -42,6 +42,10 @@
 #include "attributes.h"
 #include "macros.h"
 
+#ifndef	UINT64_C
+#define	UINT64_C(c)	(c ## UL)
+#endif
+
 //rounded division & shift
 #define RSHIFT(a,b) ((a) > 0 ? ((a) + ((1<<(b))>>1))>>(b) : ((a) + ((1<<(b))>>1)-1)>>(b))
 /* assume b>0 */
