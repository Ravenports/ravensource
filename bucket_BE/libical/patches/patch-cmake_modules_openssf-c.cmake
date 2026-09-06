--- cmake/modules/openssf-c.cmake.orig	2026-08-15 19:07:32 UTC
+++ cmake/modules/openssf-c.cmake
@@ -130,10 +130,6 @@ check_linker_flag(C "-Wl,-z,relro" C_LIN
 if(C_LINKER_SUPPORTS_RELRO)
   set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-z,relro")
 endif()
-check_linker_flag(C "-Wl,-z,now" C_LINKER_SUPPORTS_NOW)
-if(C_LINKER_SUPPORTS_NOW)
-  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-z,relro")
-endif()
 check_linker_flag(C "-Wl,--as-needed" C_LINKER_SUPPORTS_AS_NEEDED)
 if(C_LINKER_SUPPORTS_AS_NEEDED)
   set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--as-needed")
