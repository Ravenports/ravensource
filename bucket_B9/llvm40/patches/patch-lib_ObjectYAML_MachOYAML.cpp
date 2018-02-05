--- lib/ObjectYAML/MachOYAML.cpp.orig	2016-12-22 21:58:03 UTC
+++ lib/ObjectYAML/MachOYAML.cpp
@@ -19,6 +19,18 @@
 
 #include <string.h> // For memcpy, memset and strnlen.
 
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
 
 MachOYAML::LoadCommand::~LoadCommand() {}
