--- input.h.orig	2023-01-22 21:02:06 UTC
+++ input.h
@@ -17,6 +17,10 @@
 #include <linux/types.h>
 #endif
 
+#if defined(__NetBSD__)
+#define	_IOWINT(g,n)	_IOC(IOC_VOID, (g), (n), sizeof(int))
+#endif
+
 #include "input-event-codes.h"
 
 /*
