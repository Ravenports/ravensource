--- cmake/FindZstd.cmake.orig	2025-03-22 12:55:22 UTC
+++ cmake/FindZstd.cmake
@@ -5,7 +5,7 @@ if(DEPS STREQUAL "DOWNLOAD" OR DEP_ZSTD
   set(_download_zstd TRUE)
 else()
   find_path(ZSTD_INCLUDE_DIR zstd.h)
-  find_library(ZSTD_LIBRARY zstd)
+  find_library(ZSTD_LIBRARY zstd_pic)
   if(ZSTD_INCLUDE_DIR AND ZSTD_LIBRARY)
     file(READ "${ZSTD_INCLUDE_DIR}/zstd.h" _zstd_h)
     string(REGEX MATCH "#define ZSTD_VERSION_MAJOR +([0-9]+).*#define ZSTD_VERSION_MINOR +([0-9]+).*#define ZSTD_VERSION_RELEASE +([0-9]+)" _ "${_zstd_h}")
