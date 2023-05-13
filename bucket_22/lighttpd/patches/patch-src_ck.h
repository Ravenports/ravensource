--- src/ck.h.orig	2023-05-10 07:20:55 UTC
+++ src/ck.h
@@ -18,11 +18,12 @@
 #endif
 #endif
 #include "first.h"
-#if defined(__FreeBSD__) || defined(__sun)
+#if defined(__FreeBSD__) || defined(__sun) || defined(__DragonFly__)
 #ifndef _RSIZE_T_DEFINED /* expecting __EXT1_VISIBLE 1 and _RSIZE_T_DEFINED */
 #define _RSIZE_T_DEFINED
 typedef size_t rsize_t;
 #endif
+#include <stdlib.h>
 #include <errno.h>
 #endif
 
