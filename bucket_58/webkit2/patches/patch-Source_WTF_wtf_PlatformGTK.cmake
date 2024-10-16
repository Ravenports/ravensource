--- Source/WTF/wtf/PlatformGTK.cmake.orig	2024-08-19 06:28:38 UTC
+++ Source/WTF/wtf/PlatformGTK.cmake
@@ -57,7 +57,7 @@ if (CMAKE_SYSTEM_NAME MATCHES "Linux")
 
         unix/MemoryPressureHandlerUnix.cpp
     )
-elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD|DragonFly|MidnightBSD")
     list(APPEND WTF_SOURCES
         generic/MemoryFootprintGeneric.cpp
 
