--- src/external/rawspeed/cmake/compiler-flags.cmake.orig	2025-12-11 00:57:45 UTC
+++ src/external/rawspeed/cmake/compiler-flags.cmake
@@ -34,8 +34,10 @@ set(CMAKE_C_VISIBILITY_PRESET hidden)
 set(CMAKE_CXX_VISIBILITY_PRESET hidden)
 set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
 
-IF(NOT APPLE AND NOT WIN32)
+IF(NOT APPLE AND NOT WIN32 AND NOT CMAKE_SYSTEM_NAME MATCHES "SunOS")
   set(linkerflags "-Wl,--as-needed")
+ELSEIF(CMAKE_SYSTEM_NAME MATCHES "SunOS")
+  set(linkerflags "-Wl,-z,ignore")
 ELSE()
   set(linkerflags "")
 ENDIF()
