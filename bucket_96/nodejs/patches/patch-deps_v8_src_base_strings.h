--- deps/v8/src/base/strings.h.orig	2023-02-16 16:14:43 UTC
+++ deps/v8/src/base/strings.h
@@ -5,6 +5,7 @@
 #ifndef V8_BASE_STRINGS_H_
 #define V8_BASE_STRINGS_H_
 
+#include <stdarg.h> // for va_list
 #include "src/base/base-export.h"
 #include "src/base/macros.h"
 #include "src/base/vector.h"
