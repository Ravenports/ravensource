--- kde-modules/KDECompilerSettings.cmake.orig	2026-03-07 20:28:57 UTC
+++ kde-modules/KDECompilerSettings.cmake
@@ -445,9 +445,11 @@ endif()
 if (UNIX AND NOT APPLE AND NOT CYGWIN)
     # Enable adding DT_RUNPATH, which means that LD_LIBRARY_PATH takes precedence
     # over the built-in rPath
+  if (NOT CMAKE_SYSTEM_NAME MATCHES "SunOS") 
     set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--enable-new-dtags ${CMAKE_SHARED_LINKER_FLAGS}")
     set(CMAKE_MODULE_LINKER_FLAGS "-Wl,--enable-new-dtags ${CMAKE_MODULE_LINKER_FLAGS}")
     set(CMAKE_EXE_LINKER_FLAGS    "-Wl,--enable-new-dtags ${CMAKE_EXE_LINKER_FLAGS}")
+  endif()
 endif()
 
 if (CMAKE_SYSTEM_NAME STREQUAL GNU)
@@ -564,8 +566,10 @@ if ((CMAKE_CXX_COMPILER_ID STREQUAL "GNU
         (CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND NOT APPLE) OR
         (CMAKE_CXX_COMPILER_ID STREQUAL "Intel" AND NOT WIN32))
     # Linker warnings should be treated as errors
+  if (NOT CMAKE_SYSTEM_NAME MATCHES "SunOS")
     set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--fatal-warnings ${CMAKE_SHARED_LINKER_FLAGS}")
     set(CMAKE_MODULE_LINKER_FLAGS "-Wl,--fatal-warnings ${CMAKE_MODULE_LINKER_FLAGS}")
+  endif()
 
     string(TOUPPER "CMAKE_CXX_FLAGS_${CMAKE_BUILD_TYPE}" compileflags)
     if("${CMAKE_CXX_FLAGS} ${${compileflags}}" MATCHES "-fsanitize")
