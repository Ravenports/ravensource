--- MachO/ExportTrie.cpp.orig	2021-02-03 21:51:10 UTC
+++ MachO/ExportTrie.cpp
@@ -34,6 +34,20 @@
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
 #include "ExportTrie.h"
 #include "Symbols.h"
 
