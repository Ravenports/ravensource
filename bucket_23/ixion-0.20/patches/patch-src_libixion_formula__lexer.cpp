--- src/libixion/formula_lexer.cpp.orig	2025-01-28 03:56:03 UTC
+++ src/libixion/formula_lexer.cpp
@@ -16,6 +16,10 @@
 #include <unordered_map>
 #include <optional>
 
+#if defined(__sun)
+#undef _C
+#endif
+
 #include <mdds/trie_map.hpp>
 
 namespace ixion {
