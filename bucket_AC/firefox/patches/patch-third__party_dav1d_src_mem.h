--- third_party/dav1d/src/mem.h.orig	2021-03-18 13:51:06 UTC
+++ third_party/dav1d/src/mem.h
@@ -31,7 +31,7 @@
 #include <stdlib.h>
 
 #if defined(HAVE_ALIGNED_MALLOC) || defined(HAVE_MEMALIGN)
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 #include "common/attributes.h"
