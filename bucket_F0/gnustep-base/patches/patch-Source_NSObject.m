--- Source/NSObject.m.orig	2024-05-27 06:57:03 UTC
+++ Source/NSObject.m
@@ -58,6 +58,10 @@
 #include	<malloc.h>
 #endif
 
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+#include <malloc_np.h>  // for malloc_usable_size
+#endif
+
 #import "GSPThread.h"
 
 #if	defined(HAVE_SYS_SIGNAL_H)
