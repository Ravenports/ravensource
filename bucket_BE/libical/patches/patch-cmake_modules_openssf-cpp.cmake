--- cmake/modules/openssf-cpp.cmake.orig	2026-08-15 19:07:32 UTC
+++ cmake/modules/openssf-cpp.cmake
@@ -130,10 +130,6 @@ check_linker_flag(CXX "-Wl,-z,relro" CXX
 if(CXX_LINKER_SUPPORTS_RELRO)
   set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-z,relro")
 endif()
-check_linker_flag(CXX "-Wl,-z,now" CXX_LINKER_SUPPORTS_NOW)
-if(CXX_LINKER_SUPPORTS_NOW)
-  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-z,relro")
-endif()
 check_linker_flag(CXX "-Wl,--as-needed" CXX_LINKER_SUPPORTS_AS_NEEDED)
 if(CXX_LINKER_SUPPORTS_AS_NEEDED)
   set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--as-needed")
