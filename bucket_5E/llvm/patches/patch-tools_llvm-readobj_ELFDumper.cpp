--- tools/llvm-readobj/ELFDumper.cpp.orig	2021-06-28 16:23:38 UTC
+++ tools/llvm-readobj/ELFDumper.cpp
@@ -66,6 +66,20 @@
 #include <system_error>
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
