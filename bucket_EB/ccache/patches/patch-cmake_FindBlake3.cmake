--- cmake/FindBlake3.cmake.orig	2025-03-22 12:55:22 UTC
+++ cmake/FindBlake3.cmake
@@ -5,7 +5,7 @@ if(DEP_BLAKE3 STREQUAL "BUNDLED")
   message(STATUS "Using bundled Blake3 as requested")
 else()
   find_path(BLAKE3_INCLUDE_DIR blake3.h)
-  find_library(BLAKE3_LIBRARY blake3)
+  find_library(BLAKE3_LIBRARY blake3_pic)
   if(BLAKE3_INCLUDE_DIR)
     file(READ "${BLAKE3_INCLUDE_DIR}/blake3.h" _blake3_h)
     string(REGEX MATCH "#define BLAKE3_VERSION_STRING \"([0-9]+).([0-9]+).*([0-9]+)\"" _ "${_blake3_h}")
