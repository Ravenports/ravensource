--- src/augprint.c.orig	2026-09-29 22:03:14 UTC
+++ src/augprint.c
@@ -74,6 +74,14 @@
 #include <unistd.h>
 #include "augprint.h"
 
+#ifndef MIN
+# define MIN(a, b) (((a) < (b)) ? (a) : (b))
+#endif
+
+#ifndef MAX
+# define MAX(a, b) (((a) > (b)) ? (a) : (b))
+#endif
+
 #define CHECK_OOM(condition, action, arg)         \
     do {                                          \
         if (condition) {                          \
