--- cmake/FindXxhash.cmake.orig	2026-05-04 17:00:39 UTC
+++ cmake/FindXxhash.cmake
@@ -43,7 +43,7 @@ if(_download_xxhash)
   include(FetchContent)
   FetchContent_Declare(
     Xxhash
-    URL "https://github.com/Cyan4973/xxhash/archive/refs/tags/v${_xxhash_version_string}.tar.gz"
+    URL "file:///distfiles/ccache/v${_xxhash_version_string}.tar.gz"
     URL_HASH SHA256=aae608dfe8213dfd05d909a57718ef82f30722c392344583d3f39050c7f29a80
   )
   FetchContent_MakeAvailable(Xxhash)
