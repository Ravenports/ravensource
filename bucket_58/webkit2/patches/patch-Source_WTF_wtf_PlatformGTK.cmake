--- Source/WTF/wtf/PlatformGTK.cmake.orig	2022-02-23 11:41:47 UTC
+++ Source/WTF/wtf/PlatformGTK.cmake
@@ -58,7 +58,7 @@ if (CMAKE_SYSTEM_NAME MATCHES "Linux")
 
         unix/MemoryPressureHandlerUnix.cpp
     )
-elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD|DragonFly")
     list(APPEND WTF_SOURCES
         generic/MemoryFootprintGeneric.cpp
 
