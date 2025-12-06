--- cmake/ShibokenHelpers.cmake.orig	2025-11-18 11:43:26 UTC
+++ cmake/ShibokenHelpers.cmake
@@ -73,7 +73,7 @@ if(MSVC)
 else()
     set (gcc_warnings_options "-Wall -Wextra -Wno-strict-aliasing")
     # Clang has -Wno-bad-function-cast, but does not need it.
-    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL  "GNU")
+    if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU|Clang")
         set (gcc_warnings_options "${gcc_warnings_options} -Wno-cast-function-type")
     endif()
     if(CMAKE_HOST_UNIX AND NOT CYGWIN)
@@ -809,7 +809,7 @@ export DYLD_FRAMEWORK_PATH=${path_dirs_n
 $@")
     else()
         string(REPLACE ";" ":" path_dirs_native "${path_dirs_native}")
-        file(WRITE "${wrapper_path}" "#!/bin/bash
+        file(WRITE "${wrapper_path}" "#!/bin/sh
 export LD_LIBRARY_PATH=${path_dirs_native}:$LD_LIBRARY_PATH
 $@")
     endif()
