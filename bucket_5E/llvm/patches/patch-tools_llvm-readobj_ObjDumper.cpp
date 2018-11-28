--- tools/llvm-readobj/ObjDumper.cpp.orig	2018-07-26 15:31:41 UTC
+++ tools/llvm-readobj/ObjDumper.cpp
@@ -20,6 +20,18 @@
 #include "llvm/Support/ScopedPrinter.h"
 #include "llvm/Support/raw_ostream.h"
 
+#ifdef __sun__
+static size_t
+strnlen(const char *s, size_t maxlen)
+{
+	size_t len;
+	for (len = 0; len < maxlen; len++, s++) {
+		if (!*s) break;
+	}
+	return (len);
+}
+#endif
+
 namespace llvm {
 
 ObjDumper::ObjDumper(ScopedPrinter &Writer) : W(Writer) {}
