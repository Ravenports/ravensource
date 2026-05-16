--- Source/WTF/wtf/PlatformGTK.cmake.orig	2026-02-23 14:40:54 UTC
+++ Source/WTF/wtf/PlatformGTK.cmake
@@ -66,7 +66,7 @@ if (CMAKE_SYSTEM_NAME MATCHES "Linux")
 
         unix/MemoryPressureHandlerUnix.cpp
     )
-elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD" OR CMAKE_SYSTEM_NAME MATCHES "QNX")
+elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD|QNX|DragonFly|MidnightBSD")
     list(APPEND WTF_SOURCES
         generic/MemoryFootprintGeneric.cpp
 
