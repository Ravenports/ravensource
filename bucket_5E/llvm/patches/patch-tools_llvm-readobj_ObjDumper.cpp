--- tools/llvm-readobj/ObjDumper.cpp.orig	2021-04-06 16:38:18 UTC
+++ tools/llvm-readobj/ObjDumper.cpp
@@ -20,6 +20,18 @@
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
