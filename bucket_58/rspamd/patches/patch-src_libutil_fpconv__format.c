--- src/libutil/fpconv_format.c.orig	2026-08-15 10:50:53 UTC
+++ src/libutil/fpconv_format.c
@@ -6,6 +6,14 @@
 #include "fpconv_format.h"
 #include "contrib/fpconv/fpconv.h"
 
+#ifndef MIN
+#define MIN(a,b) (((a)<(b))?(a):(b))
+#endif
+
+#ifndef MAX
+#define MAX(a,b) (((a)>(b))?(a):(b))
+#endif
+
 /*
  * Grisu2 produces at most 17 significant digits, so any explicit
  * precision in [1..17] is safe to use for fixed-width padding.
