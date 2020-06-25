--- pr/include/md/prosdep.h.orig	2020-06-24 13:26:09 UTC
+++ pr/include/md/prosdep.h
@@ -43,6 +43,9 @@ PR_BEGIN_EXTERN_C
 #elif defined(OPENBSD)
 #include "md/_openbsd.h"
 
+#elif defined(__DragonFly__)
+#include "md/_dragonfly.h"
+
 #elif defined(BSDI)
 #include "md/_bsdi.h"
 
