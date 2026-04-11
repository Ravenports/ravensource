--- utils.h.orig	2023-05-31 08:25:59 UTC
+++ utils.h
@@ -30,6 +30,13 @@
 
 #include "minidlnatypes.h"
 
+#ifndef MIN
+#define MIN(a,b) (((a)<(b))?(a):(b))
+#endif
+#ifndef MAX
+#define MAX(a,b) (((a)>(b))?(a):(b))
+#endif
+
 /* String functions */
 /* We really want this one inlined, since it has a major performance impact */
 static inline int
