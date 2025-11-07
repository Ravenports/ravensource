--- CMake/Platforms.cmake.orig	2025-11-07 15:53:10 UTC
+++ CMake/Platforms.cmake
@@ -2,14 +2,14 @@ if(HAIKU)
   include(platforms/haiku)
 endif()
 
-if(CMAKE_SYSTEM_NAME MATCHES "FreeBSD|OpenBSD|DragonFly|NetBSD")
+if(CMAKE_SYSTEM_NAME MATCHES "FreeBSD|OpenBSD|DragonFly|NetBSD|MidnightBSD")
   if(CMAKE_SYSTEM_NAME MATCHES "NetBSD")
     add_definitions(-D_NETBSD_SOURCE)
   else()
-    add_definitions(-D_BSD_SOURCE)
     set(UBSAN OFF)
   endif()
   set(ASAN OFF)
+  add_definitions(-D_BSD_SOURCE)
   add_definitions(-DO_LARGEFILE=0 -Dstat64=stat -Dlstat64=lstat -Dlseek64=lseek -Doff64_t=off_t -Dfstat64=fstat -Dftruncate64=ftruncate)
 endif()
 
