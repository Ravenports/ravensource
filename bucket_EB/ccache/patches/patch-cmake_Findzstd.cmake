--- cmake/Findzstd.cmake.orig	2023-06-12 19:17:31 UTC
+++ cmake/Findzstd.cmake
@@ -25,7 +25,7 @@ else()
   endif()
 
   if(NOT zstd_FOUND)
-    find_library(ZSTD_LIBRARY zstd)
+    find_library(ZSTD_LIBRARY zstd_pic)
     find_path(ZSTD_INCLUDE_DIR zstd.h)
     if(ZSTD_LIBRARY AND ZSTD_INCLUDE_DIR)
       message(STATUS "Using zstd from ${ZSTD_LIBRARY}")
