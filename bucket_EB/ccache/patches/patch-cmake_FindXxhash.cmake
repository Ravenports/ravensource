--- cmake/FindXxhash.cmake.orig	2024-06-30 18:46:01 UTC
+++ cmake/FindXxhash.cmake
@@ -39,7 +39,7 @@ if(_download_xxhash)
   include(FetchContent)
   FetchContent_Declare(
     Xxhash
-    URL "https://github.com/Cyan4973/xxhash/archive/refs/tags/v${_xxhash_version_string}.tar.gz"
+    URL "file:///distfiles/ccache/v${_xxhash_version_string}.tar.gz"
     URL_HASH SHA256=baee0c6afd4f03165de7a4e67988d16f0f2b257b51d0e3cb91909302a26a79c4
   )
 
