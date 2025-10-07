--- gtk/roaring/roaring.h.orig	2025-09-08 20:57:32 UTC
+++ gtk/roaring/roaring.h
@@ -89,7 +89,6 @@ enum {
 #include <stdint.h>
 #include <stdlib.h>  // will provide posix_memalign with _POSIX_C_SOURCE as defined above
 #ifdef __GLIBC__
-#include <malloc.h>  // this should never be needed but there are some reports that it is needed.
 #endif
 
 #ifdef __cplusplus
