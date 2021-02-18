--- tools/llvm-objcopy/MachO/MachOLayoutBuilder.cpp.orig	2021-02-03 21:51:10 UTC
+++ tools/llvm-objcopy/MachO/MachOLayoutBuilder.cpp
@@ -11,6 +11,18 @@
 #include "llvm/Support/Errc.h"
 #include "llvm/Support/ErrorHandling.h"
 
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
