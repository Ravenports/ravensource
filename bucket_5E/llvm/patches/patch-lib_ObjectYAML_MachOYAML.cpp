--- lib/ObjectYAML/MachOYAML.cpp.orig	2021-02-03 21:51:10 UTC
+++ lib/ObjectYAML/MachOYAML.cpp
@@ -21,6 +21,18 @@
 #include <cstdint>
 #include <cstring>
 
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
 
 MachOYAML::LoadCommand::~LoadCommand() = default;
