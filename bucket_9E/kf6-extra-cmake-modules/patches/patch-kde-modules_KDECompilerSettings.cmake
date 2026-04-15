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
