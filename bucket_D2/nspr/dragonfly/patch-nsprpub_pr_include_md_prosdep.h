--- pr/include/md/prosdep.h.orig	2018-01-18 12:37:14 UTC
+++ pr/include/md/prosdep.h
@@ -43,6 +43,9 @@ PR_BEGIN_EXTERN_C
 #elif defined(OPENBSD)
 #include "md/_openbsd.h"
 
+#elif defined(__DragonFly__)
+#include "md/_dragonfly.h"
+
 #elif defined(BSDI)
 #include "md/_bsdi.h"
 
