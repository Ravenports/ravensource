--- Source/WTF/wtf/PlatformGTK.cmake.orig	2025-02-25 08:25:40 UTC
+++ Source/WTF/wtf/PlatformGTK.cmake
@@ -61,7 +61,7 @@ if (CMAKE_SYSTEM_NAME MATCHES "Linux")
 
         unix/MemoryPressureHandlerUnix.cpp
     )
-elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD|DragonFly|MidnightBSD")
     list(APPEND WTF_SOURCES
         generic/MemoryFootprintGeneric.cpp
 
