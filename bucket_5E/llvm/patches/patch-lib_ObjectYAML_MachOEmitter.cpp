--- lib/ObjectYAML/MachOEmitter.cpp.orig	2021-06-28 16:23:38 UTC
+++ lib/ObjectYAML/MachOEmitter.cpp
@@ -23,6 +23,18 @@
 
 #include "llvm/Support/Format.h"
 
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
 using namespace llvm;
 
 namespace {
