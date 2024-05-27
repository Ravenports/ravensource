--- Source/GSString.m.orig	2023-01-08 08:41:32 UTC
+++ Source/GSString.m
@@ -58,6 +58,10 @@
 #include <alloca.h>
 #endif
 
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+#include <malloc_np.h>  // for malloc_usable_size()
+#endif
+
 /* memcpy(), strlen(), strcmp() are gcc builtin's */
 
 #import "GNUstepBase/Unicode.h"
