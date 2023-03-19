--- cmake/Findzstd.cmake.orig	2023-03-12 21:00:43 UTC
+++ cmake/Findzstd.cmake
@@ -20,7 +20,7 @@ else()
   endif()
 
   if(NOT zstd_FOUND)
-    find_library(ZSTD_LIBRARY zstd)
+    find_library(ZSTD_LIBRARY zstd_pic)
     find_path(ZSTD_INCLUDE_DIR zstd.h)
     if(ZSTD_LIBRARY AND ZSTD_INCLUDE_DIR)
       message(STATUS "Using zstd from ${ZSTD_LIBRARY}")
