--- cmake/Findzstd.cmake.orig	2021-03-27 18:54:20 UTC
+++ cmake/Findzstd.cmake
@@ -41,7 +41,7 @@ if(ZSTD_FROM_INTERNET)
 
   set(zstd_FOUND TRUE)
 else()
-  find_library(ZSTD_LIBRARY zstd)
+  find_library(ZSTD_LIBRARY zstd_pic)
   find_path(ZSTD_INCLUDE_DIR zstd.h)
 
   include(FindPackageHandleStandardArgs)
