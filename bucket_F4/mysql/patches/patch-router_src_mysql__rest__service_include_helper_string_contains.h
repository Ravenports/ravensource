--- router/src/mysql_rest_service/include/helper/string/contains.h.orig	2025-07-09 08:56:06 UTC
+++ router/src/mysql_rest_service/include/helper/string/contains.h
@@ -85,7 +85,12 @@ bool index(const std::string &value, con
 inline bool index(const char *value, const char *search_for, uint32_t *idx) {
   auto ptr = strstr(value, search_for);
   if (nullptr == ptr) return false;
+#if defined(__linux__)
   if (idx) *idx = static_cast<uint32_t>(std::distance(value, ptr));
+#else
+  char* char_value = const_cast<char*>(value);
+  if (idx) *idx = static_cast<uint32_t>(std::distance(char_value, ptr));
+#endif
   return true;
 }
 
