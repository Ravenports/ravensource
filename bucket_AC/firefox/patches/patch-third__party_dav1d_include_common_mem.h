--- third_party/dav1d/include/common/mem.h.orig	2020-12-21 19:07:42 UTC
+++ third_party/dav1d/include/common/mem.h
@@ -30,9 +30,6 @@
 
 #include <stdlib.h>
 
-#if defined(HAVE_ALIGNED_MALLOC) || defined(HAVE_MEMALIGN)
-#include <malloc.h>
-#endif
 
 #include "common/attributes.h"
 
