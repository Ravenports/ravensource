--- pr/include/md/prosdep.h.orig	2025-11-05 10:29:01 UTC
+++ pr/include/md/prosdep.h
@@ -34,6 +34,9 @@ PR_BEGIN_EXTERN_C
 #elif defined(FREEBSD)
 #include "md/_freebsd.h"
 
+#elif defined(__DragonFly__)
+#include "md/_dragonfly.h"
+
 #elif defined(NETBSD)
 #include "md/_netbsd.h"
 
