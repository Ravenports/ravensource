--- Source/NSObject.m.orig	2023-01-08 08:41:32 UTC
+++ Source/NSObject.m
@@ -57,6 +57,10 @@
 #include	<malloc.h>
 #endif
 
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+#include <malloc_np.h>  // for malloc_usable_size
+#endif
+
 #import "GSPThread.h"
 
 #if	defined(HAVE_SYS_SIGNAL_H)
