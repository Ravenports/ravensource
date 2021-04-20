--- tools/llvm-objcopy/MachO/Object.cpp.orig	2021-04-06 16:38:18 UTC
+++ tools/llvm-objcopy/MachO/Object.cpp
@@ -10,6 +10,18 @@
 #include "llvm/ADT/SmallPtrSet.h"
 #include <unordered_set>
 
+#ifdef __sun__
+static size_t
+strnlen(const char *s, size_t maxlen)
+{
+       size_t len;
+       for (len = 0; len < maxlen; len++, s++) {
+               if (!*s) break;
+       }
+       return (len);
+}
+#endif
+
 namespace llvm {
 namespace objcopy {
 namespace macho {
