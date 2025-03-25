--- src/ck.h.orig	2025-03-22 19:40:18 UTC
+++ src/ck.h
@@ -23,6 +23,7 @@
 #define _RSIZE_T_DEFINED
 typedef size_t rsize_t;
 #endif
+#include <stdlib.h>
 #include <errno.h>
 #if defined(__DragonFly__)
 typedef int errno_t;
