--- deps/v8/src/common/globals.h.orig	2021-11-09 13:29:19 UTC
+++ deps/v8/src/common/globals.h
@@ -7,6 +7,7 @@
 
 #include <stddef.h>
 #include <stdint.h>
+#include <stdarg.h> // for va_list
 
 #include <limits>
 #include <ostream>
