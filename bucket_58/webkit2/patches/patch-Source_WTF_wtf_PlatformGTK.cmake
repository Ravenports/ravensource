--- Source/WTF/wtf/PlatformGTK.cmake.orig	2021-02-26 09:57:08 UTC
+++ Source/WTF/wtf/PlatformGTK.cmake
@@ -54,7 +54,7 @@ if (CMAKE_SYSTEM_NAME MATCHES "Linux")
 
         unix/MemoryPressureHandlerUnix.cpp
     )
-elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD|DragonFly")
     list(APPEND WTF_SOURCES
         generic/MemoryFootprintGeneric.cpp
 
