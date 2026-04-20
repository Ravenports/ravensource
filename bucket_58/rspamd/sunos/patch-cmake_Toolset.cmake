--- cmake/Toolset.cmake.orig	2026-01-08 13:17:41 UTC
+++ cmake/Toolset.cmake
@@ -85,9 +85,6 @@ endif ()
 
 option(LINKER_NAME "Linker name or full path")
 
-find_program(LLD_PATH NAMES "ld.lld" "lld")
-find_program(GOLD_PATH NAMES "ld.gold" "gold")
-
 if(NOT LINKER_NAME)
     if(LLD_PATH)
         if (COMPILER_CLANG)
@@ -108,13 +105,6 @@ if(NOT LINKER_NAME)
     endif()
 endif()
 
-if(LINKER_NAME)
-    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=${LINKER_NAME}")
-    set (CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -fuse-ld=${LINKER_NAME}")
-
-    message(STATUS "Using custom linker by name: ${LINKER_NAME}")
-endif ()
-
 option (ENABLE_STATIC       "Enable static compiling [default: OFF]"             OFF)
 
 if (ENABLE_STATIC MATCHES "ON")
