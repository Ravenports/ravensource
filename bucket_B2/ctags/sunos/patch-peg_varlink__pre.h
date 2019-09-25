--- peg/varlink_pre.h.orig	Thu Sep 19 01:20:45 2019
+++ peg/varlink_pre.h	Thu Sep 19 01:37:54 2019
@@ -19,6 +19,14 @@
 #include "read.h"
 
 
+#if defined(sun) || defined(__sun)
+ static size_t strnlen(const char *str, size_t maxlen) {
+     size_t i;
+     for (i = 0; str[i] && i < maxlen; i++);
+     return i;
+ }
+#endif
+
 /*
 *   MACROS
 */
