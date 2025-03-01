--- Source/GSString.m.orig	2025-02-10 17:00:46 UTC
+++ Source/GSString.m
@@ -57,6 +57,10 @@
 #include <alloca.h>
 #endif
 
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+#include <malloc_np.h>  // for malloc_usable_size()
+#endif
+
 /* memcpy(), strlen(), strcmp() are gcc builtin's */
 
 #import "GNUstepBase/Unicode.h"
