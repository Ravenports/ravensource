--- MachO/InputFiles.cpp.orig	2022-01-20 21:31:59 UTC
+++ MachO/InputFiles.cpp
@@ -41,6 +41,22 @@
 //
 //===----------------------------------------------------------------------===//
 
+#ifdef __sun__
+#include <string.h>
+
+extern "C" {
+  static size_t
+  strnlen(const char *s, size_t maxlen)
+  {
+       size_t len;
+       for (len = 0; len < maxlen; len++, s++) {
+               if (!*s) break;
+       }
+       return (len);
+  }
+}
+#endif
+
 #include "InputFiles.h"
 #include "Config.h"
 #include "Driver.h"
