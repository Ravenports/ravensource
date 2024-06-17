--- cmake/OpenCVCompilerOptions.cmake.orig	2024-06-02 11:41:07 UTC
+++ cmake/OpenCVCompilerOptions.cmake
@@ -385,7 +385,6 @@ endif()
 # Apply "-Wl,--no-undefined" linker flags: https://github.com/opencv/opencv/pull/21347
 if(NOT OPENCV_SKIP_LINK_NO_UNDEFINED)
   if(UNIX AND ((NOT APPLE OR NOT CMAKE_VERSION VERSION_LESS "3.2") AND NOT CMAKE_SYSTEM_NAME MATCHES "OpenBSD"))
-    set(_option "-Wl,--no-undefined")
     set(_saved_CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
     set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${_option}")  # requires CMake 3.2+ and CMP0056
     ocv_check_compiler_flag(CXX "" HAVE_LINK_NO_UNDEFINED)
