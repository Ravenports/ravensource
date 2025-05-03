--- cmake/FindXxhash.cmake.orig	2025-05-03 08:48:34 UTC
+++ cmake/FindXxhash.cmake
@@ -39,7 +39,7 @@ if(_download_xxhash)
   include(FetchContent)
   FetchContent_Declare(
     Xxhash
-    URL "https://github.com/Cyan4973/xxhash/archive/refs/tags/v${_xxhash_version_string}.tar.gz"
+    URL "file:///distfiles/ccache/v${_xxhash_version_string}.tar.gz"
     URL_HASH SHA256=aae608dfe8213dfd05d909a57718ef82f30722c392344583d3f39050c7f29a80
   )
 
