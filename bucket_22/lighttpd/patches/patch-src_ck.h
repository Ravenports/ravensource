--- src/ck.h.orig	2021-12-04 14:40:24 UTC
+++ src/ck.h
@@ -18,11 +18,12 @@
 #endif
 #endif
 #include "first.h"
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__
 #ifndef _RSIZE_T_DEFINED /* expecting __EXT1_VISIBLE 1 and _RSIZE_T_DEFINED */
 #define _RSIZE_T_DEFINED
 typedef size_t rsize_t;
 #endif
+#include <stdlib.h>
 #include <errno.h>
 #endif
 
