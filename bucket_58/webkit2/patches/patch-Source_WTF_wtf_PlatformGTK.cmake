--- Source/WTF/wtf/PlatformGTK.cmake.orig	2025-08-11 07:56:53 UTC
+++ Source/WTF/wtf/PlatformGTK.cmake
@@ -63,7 +63,7 @@ if (CMAKE_SYSTEM_NAME MATCHES "Linux")
 
         unix/MemoryPressureHandlerUnix.cpp
     )
-elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD|DragonFly|MidnightBSD")
     list(APPEND WTF_SOURCES
         generic/MemoryFootprintGeneric.cpp
 
