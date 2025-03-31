--- cmake/OpenCVGenPkgconfig.cmake.orig	2025-01-08 12:47:46 UTC
+++ cmake/OpenCVGenPkgconfig.cmake
@@ -110,7 +110,7 @@ endif()
 # =============================================================================
 else() # DEFINED CMAKE_HELPER_SCRIPT
 
-cmake_minimum_required(VERSION 2.8.12.2)
+cmake_minimum_required(VERSION 3.5)
 cmake_policy(SET CMP0012 NEW)
 include("${CMAKE_HELPER_SCRIPT}")
 include("${OpenCV_SOURCE_DIR}/cmake/OpenCVUtils.cmake")
