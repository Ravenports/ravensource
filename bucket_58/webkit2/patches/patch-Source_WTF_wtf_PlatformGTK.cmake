--- Source/WTF/wtf/PlatformGTK.cmake.orig	2021-09-01 09:16:49 UTC
+++ Source/WTF/wtf/PlatformGTK.cmake
@@ -55,7 +55,7 @@ if (CMAKE_SYSTEM_NAME MATCHES "Linux")
 
         unix/MemoryPressureHandlerUnix.cpp
     )
-elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD|DragonFly")
     list(APPEND WTF_SOURCES
         generic/MemoryFootprintGeneric.cpp
 
