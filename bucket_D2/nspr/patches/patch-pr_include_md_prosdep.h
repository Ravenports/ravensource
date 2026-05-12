--- pr/include/md/prosdep.h.orig	2026-05-05 12:48:55 UTC
+++ pr/include/md/prosdep.h
@@ -33,6 +33,9 @@ PR_BEGIN_EXTERN_C
 #elif defined(FREEBSD)
 #include "md/_freebsd.h"
 
+#elif defined(__DragonFly__)
+#include "md/_dragonfly.h"
+
 #elif defined(NETBSD)
 #include "md/_netbsd.h"
 
