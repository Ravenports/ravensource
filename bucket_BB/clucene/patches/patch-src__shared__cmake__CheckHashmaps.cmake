--- src/shared/cmake/CheckHashmaps.cmake.orig	2011-03-17 00:21:07 UTC
+++ src/shared/cmake/CheckHashmaps.cmake
@@ -35,8 +35,12 @@ MACRO(HASHMAP_TEST HashingValue namespac
 #elif defined(_CL_HAVE_EXT_HASH_MAP)
 	#include <ext/hash_map>
 #elif defined(_CL_HAVE_TR1_UNORDERED_MAP)
+#if defined(_LIBCPP_VERSION)
+	#include <unordered_map>
+#else
 	#include <tr1/unordered_map>
 #endif
+#endif
 int main() {  
     ${namespace}::${_CL_HASH_MAP}<int,char> a; 
     return 0; 
