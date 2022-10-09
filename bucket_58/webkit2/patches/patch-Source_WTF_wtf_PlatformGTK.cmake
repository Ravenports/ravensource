--- Source/WTF/wtf/PlatformGTK.cmake.orig	2022-09-14 11:58:10 UTC
+++ Source/WTF/wtf/PlatformGTK.cmake
@@ -61,7 +61,7 @@ if (CMAKE_SYSTEM_NAME MATCHES "Linux")
 
         unix/MemoryPressureHandlerUnix.cpp
     )
-elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD|DragonFly")
     list(APPEND WTF_SOURCES
         generic/MemoryFootprintGeneric.cpp
 
