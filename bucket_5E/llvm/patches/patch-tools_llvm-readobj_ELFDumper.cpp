--- tools/llvm-readobj/ELFDumper.cpp.orig	2021-02-03 21:51:10 UTC
+++ tools/llvm-readobj/ELFDumper.cpp
@@ -68,6 +68,20 @@
 #include <unordered_set>
 #include <vector>
 
+#ifdef __sun
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
 using namespace llvm;
 using namespace llvm::object;
 using namespace ELF;
