--- cmake/Findzstd.cmake.orig	2022-10-22 17:48:41 UTC
+++ cmake/Findzstd.cmake
@@ -10,7 +10,7 @@ if(PKG_CONFIG_FOUND)
   find_library(ZSTD_LIBRARY zstd HINTS ${PC_ZSTD_LIBDIR} ${PC_ZSTD_LIBRARY_DIRS})
   find_path(ZSTD_INCLUDE_DIR zstd.h HINTS ${PC_ZSTD_INCLUDEDIR} ${PC_ZSTD_INCLUDE_DIRS})
 else()
-  find_library(ZSTD_LIBRARY zstd)
+  find_library(ZSTD_LIBRARY zstd_pic)
   find_path(ZSTD_INCLUDE_DIR zstd.h)
 endif()
 
