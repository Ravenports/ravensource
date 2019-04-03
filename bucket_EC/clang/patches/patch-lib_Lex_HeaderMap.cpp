--- lib/Lex/HeaderMap.cpp.orig	2018-08-20 19:15:02 UTC
+++ lib/Lex/HeaderMap.cpp
@@ -24,6 +24,19 @@
 #include "llvm/Support/Debug.h"
 #include <cstring>
 #include <memory>
+
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
 using namespace clang;
 
 /// HashHMapKey - This is the 'well known' hash function required by the file
