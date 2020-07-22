--- tools/obj2yaml/macho2yaml.cpp.orig	2020-07-07 16:21:37 UTC
+++ tools/obj2yaml/macho2yaml.cpp
@@ -16,6 +16,18 @@
 
 #include <string.h> // for memcpy
 
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
 
 class MachODumper {
