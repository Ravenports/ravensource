--- third_party/dav1d/src/mem.h.orig	2025-01-13 13:46:01 UTC
+++ third_party/dav1d/src/mem.h
@@ -33,7 +33,9 @@
 #include <stdlib.h>
 
 #if defined(_WIN32) || HAVE_MEMALIGN
+# if !defined(__DragonFly__) && !defined(__FreeBSD__)
 #include <malloc.h>
+# endif
 #endif
 
 #include "dav1d/dav1d.h"
