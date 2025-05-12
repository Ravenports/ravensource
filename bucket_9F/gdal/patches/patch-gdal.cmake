--- gdal.cmake.orig	2025-05-06 16:38:15 UTC
+++ gdal.cmake
@@ -91,7 +91,7 @@ endif ()
 if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
   include(CheckLinkerFlag)
   check_linker_flag(C "-Wl,--no-undefined" HAS_NO_UNDEFINED)
-  if (HAS_NO_UNDEFINED AND (NOT "${CMAKE_CXX_FLAGS}" MATCHES "-fsanitize") AND NOT CMAKE_SYSTEM_NAME MATCHES "OpenBSD")
+  if (HAS_NO_UNDEFINED AND (NOT "${CMAKE_CXX_FLAGS}" MATCHES "-fsanitize") AND NOT CMAKE_SYSTEM_NAME MATCHES "OpenBSD|MidnightBSD|FreeBSD|DragonFly")
     string(APPEND CMAKE_SHARED_LINKER_FLAGS " -Wl,--no-undefined")
     string(APPEND CMAKE_MODULE_LINKER_FLAGS " -Wl,--no-undefined")
   endif ()
