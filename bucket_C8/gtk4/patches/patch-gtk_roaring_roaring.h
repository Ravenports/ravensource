--- gtk/roaring/roaring.h.orig	2025-10-03 18:50:24.760858000 +0200
+++ gtk/roaring/roaring.h	2025-10-03 18:50:46.926883000 +0200
@@ -89,7 +89,6 @@
 #include <stdint.h>
 #include <stdlib.h>  // will provide posix_memalign with _POSIX_C_SOURCE as defined above
 #ifdef __GLIBC__
-#include <malloc.h>  // this should never be needed but there are some reports that it is needed.
 #endif
 
 #ifdef __cplusplus
