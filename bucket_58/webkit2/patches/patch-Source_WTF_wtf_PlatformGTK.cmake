--- Source/WTF/wtf/PlatformGTK.cmake.orig	2023-02-20 09:22:13 UTC
+++ Source/WTF/wtf/PlatformGTK.cmake
@@ -62,7 +62,7 @@ if (CMAKE_SYSTEM_NAME MATCHES "Linux")
 
         unix/MemoryPressureHandlerUnix.cpp
     )
-elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD|DragonFly|MidnightBSD")
     list(APPEND WTF_SOURCES
         generic/MemoryFootprintGeneric.cpp
 
