--- lib/ObjectYAML/MachOYAML.cpp.orig	2019-12-11 19:15:30 UTC
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
