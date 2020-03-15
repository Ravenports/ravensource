--- src/liborcus/json_map_tree.cpp.orig	2019-10-10 00:46:55 UTC
+++ src/liborcus/json_map_tree.cpp
@@ -14,6 +14,8 @@
 
 namespace orcus {
 
+constexpr json_map_tree::child_position_type json_map_tree::node_child_default_position;
+
 namespace {
 
 void throw_path_error(const char* file, int line, const pstring& path)
