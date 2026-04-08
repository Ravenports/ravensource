--- src/augprint.c.orig	2023-07-14 11:07:23 UTC
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
