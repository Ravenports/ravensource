--- deps/v8/src/base/strings.h.orig	2025-09-25 14:43:12 UTC
+++ deps/v8/src/base/strings.h
@@ -5,6 +5,7 @@
 #ifndef V8_BASE_STRINGS_H_
 #define V8_BASE_STRINGS_H_
 
+#include <stdarg.h> // for va_list
 #include "src/base/base-export.h"
 #include "src/base/macros.h"
 #include "src/base/vector.h"
