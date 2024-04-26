--- Source/WTF/wtf/PlatformGTK.cmake.orig	2024-03-16 06:45:49 UTC
+++ Source/WTF/wtf/PlatformGTK.cmake
@@ -64,7 +64,7 @@ if (CMAKE_SYSTEM_NAME MATCHES "Linux")
 
         unix/MemoryPressureHandlerUnix.cpp
     )
-elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD|DragonFly|MidnightBSD")
     list(APPEND WTF_SOURCES
         generic/MemoryFootprintGeneric.cpp
 
