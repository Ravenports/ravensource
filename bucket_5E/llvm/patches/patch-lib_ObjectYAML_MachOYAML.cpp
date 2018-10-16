--- lib/ObjectYAML/MachOYAML.cpp.orig	2017-12-18 17:38:03 UTC
+++ lib/ObjectYAML/MachOYAML.cpp
@@ -22,6 +22,18 @@
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
