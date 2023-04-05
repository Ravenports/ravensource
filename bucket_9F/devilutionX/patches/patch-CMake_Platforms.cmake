--- CMake/Platforms.cmake.orig	2023-04-05 20:01:40 UTC
+++ CMake/Platforms.cmake
@@ -6,7 +6,7 @@ if(HAIKU)
   include(platforms/haiku)
 endif()
 
-if(CMAKE_SYSTEM_NAME MATCHES "FreeBSD|OpenBSD|DragonFly|NetBSD")
+if(CMAKE_SYSTEM_NAME MATCHES "FreeBSD|OpenBSD|DragonFly|NetBSD|MidnightBSD")
   if(CMAKE_SYSTEM_NAME MATCHES "NetBSD")
     add_definitions(-D_NETBSD_SOURCE)
   else()
