--- contrib/backward-cpp/backward.hpp.orig	2024-12-16 14:04:14 UTC
+++ contrib/backward-cpp/backward.hpp
@@ -415,6 +415,7 @@ extern "C" uintptr_t _Unwind_GetIPInfo(_
 #ifdef BACKWARD_ATLEAST_CXX11
 #include <unordered_map>
 #include <utility> // for std::swap
+#include <cstdint>
 namespace backward {
 namespace details {
 template <typename K, typename V> struct hashtable {
