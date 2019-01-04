--- src/gallium/auxiliary/util/u_math.h.orig	2018-12-13 14:02:20 UTC
+++ src/gallium/auxiliary/util/u_math.h
@@ -49,6 +49,9 @@
 #include "util/bitscan.h"
 
 #ifdef __cplusplus
+# ifdef __sun__
+#define restrict	__restrict__
+# endif
 extern "C" {
 #endif
 
