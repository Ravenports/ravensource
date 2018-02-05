--- tools/llvm-pdbdump/LLVMOutputStyle.cpp.orig	2017-01-11 23:24:22 UTC
+++ tools/llvm-pdbdump/LLVMOutputStyle.cpp
@@ -37,6 +37,18 @@
 
 #include <unordered_map>
 
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
 using namespace llvm::codeview;
 using namespace llvm::msf;
