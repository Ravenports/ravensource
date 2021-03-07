--- MachO/InputFiles.cpp.orig	2021-02-03 21:51:10 UTC
+++ MachO/InputFiles.cpp
@@ -41,6 +41,20 @@
 //
 //===----------------------------------------------------------------------===//
 
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
+
 #include "InputFiles.h"
 #include "Config.h"
 #include "ExportTrie.h"
