--- cmake/ShibokenHelpers.cmake.orig	2025-05-30 11:57:51 UTC
+++ cmake/ShibokenHelpers.cmake
@@ -55,7 +55,7 @@ if(MSVC)
 else()
     set (gcc_warnings_options "-Wall -Wextra -Wno-strict-aliasing")
     # Clang has -Wno-bad-function-cast, but does not need it.
-    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL  "GNU")
+    if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU|Clang")
         set (gcc_warnings_options "${gcc_warnings_options} -Wno-cast-function-type")
     endif()
     if(CMAKE_HOST_UNIX AND NOT CYGWIN)
@@ -791,7 +791,7 @@ export DYLD_FRAMEWORK_PATH=${path_dirs_n
 $@")
     else()
         string(REPLACE ";" ":" path_dirs_native "${path_dirs_native}")
-        file(WRITE "${wrapper_path}" "#!/bin/bash
+        file(WRITE "${wrapper_path}" "#!/bin/sh
 export LD_LIBRARY_PATH=${path_dirs_native}:$LD_LIBRARY_PATH
 $@")
     endif()
