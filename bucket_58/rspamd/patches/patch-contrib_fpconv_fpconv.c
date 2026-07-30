--- contrib/fpconv/fpconv.c.orig	2026-07-21 17:53:03 UTC
+++ contrib/fpconv/fpconv.c
@@ -2,6 +2,14 @@
 #include <string.h>
 #include <sys/param.h>
 
+#ifndef MIN
+#define MIN(a,b) (((a)<(b))?(a):(b))
+#endif
+
+#ifndef MAX
+#define MAX(a,b) (((a)>(b))?(a):(b))
+#endif
+
 #include "fpconv.h"
 #include "powers.h"
 
