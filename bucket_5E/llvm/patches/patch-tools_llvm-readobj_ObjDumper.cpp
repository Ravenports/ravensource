--- tools/llvm-readobj/ObjDumper.cpp.orig	2020-10-07 10:10:48 UTC
+++ tools/llvm-readobj/ObjDumper.cpp
@@ -21,6 +21,18 @@
 #include "llvm/Support/raw_ostream.h"
 #include <map>
 
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
 
 static inline Error createError(const Twine &Msg) {
