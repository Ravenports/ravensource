--- router/src/mysql_rest_service/include/helper/string/contains.h.orig	2025-03-31 08:00:22 UTC
+++ router/src/mysql_rest_service/include/helper/string/contains.h
@@ -84,7 +84,8 @@ bool index(const std::string &value, con
 inline bool index(const char *value, const char *search_for, uint32_t *idx) {
   auto ptr = strstr(value, search_for);
   if (nullptr == ptr) return false;
-  if (idx) *idx = static_cast<uint32_t>(std::distance(value, ptr));
+  char* char_value = const_cast<char*>(value);
+  if (idx) *idx = static_cast<uint32_t>(std::distance(char_value, ptr));
   return true;
 }
 
