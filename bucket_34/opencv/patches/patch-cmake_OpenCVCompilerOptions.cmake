--- cmake/OpenCVCompilerOptions.cmake.orig	2025-12-30 07:52:05 UTC
+++ cmake/OpenCVCompilerOptions.cmake
@@ -250,6 +250,10 @@ if(CV_GCC OR CV_CLANG OR CV_ICX)
           set(OPENCV_EXTRA_EXE_LINKER_FLAGS "${OPENCV_EXTRA_EXE_LINKER_FLAGS} -Wl,-dead_strip")
           set(OPENCV_EXTRA_SHARED_LINKER_FLAGS "${OPENCV_EXTRA_SHARED_LINKER_FLAGS} -Wl,-dead_strip")
           set(OPENCV_EXTRA_MODULE_LINKER_FLAGS "${OPENCV_EXTRA_MODULE_LINKER_FLAGS} -Wl,-dead_strip")
+        elseif(CMAKE_SYSTEM_NAME MATCHES "SunOS")
+          set(OPENCV_EXTRA_EXE_LINKER_FLAGS "${OPENCV_EXTRA_EXE_LINKER_FLAGS} -Wl,-z,ignore")
+          set(OPENCV_EXTRA_SHARED_LINKER_FLAGS "${OPENCV_EXTRA_SHARED_LINKER_FLAGS} -Wl,-z,ignore")
+          set(OPENCV_EXTRA_MODULE_LINKER_FLAGS "${OPENCV_EXTRA_MODULE_LINKER_FLAGS} -Wl,-z,ignore")
         else()
           set(OPENCV_EXTRA_EXE_LINKER_FLAGS "${OPENCV_EXTRA_EXE_LINKER_FLAGS} -Wl,--gc-sections")
           set(OPENCV_EXTRA_SHARED_LINKER_FLAGS "${OPENCV_EXTRA_SHARED_LINKER_FLAGS} -Wl,--gc-sections")
@@ -391,7 +395,6 @@ endif()
 # Apply "-Wl,--no-undefined" linker flags: https://github.com/opencv/opencv/pull/21347
 if(NOT OPENCV_SKIP_LINK_NO_UNDEFINED)
   if(UNIX AND ((NOT APPLE OR NOT CMAKE_VERSION VERSION_LESS "3.2") AND NOT CMAKE_SYSTEM_NAME MATCHES "OpenBSD"))
-    set(_option "-Wl,--no-undefined")
     set(_saved_CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
     set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${_option}")  # requires CMake 3.2+ and CMP0056
     ocv_check_compiler_flag(CXX "" HAVE_LINK_NO_UNDEFINED)
