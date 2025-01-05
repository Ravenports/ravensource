--- storage/rocksdb/build_rocksdb.cmake.orig	2024-11-11 07:18:45 UTC
+++ storage/rocksdb/build_rocksdb.cmake
@@ -90,7 +90,7 @@ elseif(CMAKE_SYSTEM_NAME MATCHES "Linux"
   add_definitions(-DOS_LINUX)
 elseif(CMAKE_SYSTEM_NAME MATCHES "SunOS")
   add_definitions(-DOS_SOLARIS)
-elseif(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+elseif(CMAKE_SYSTEM_NAME MATCHES "FreeBSD|MidnightBSD")
   add_definitions(-DOS_FREEBSD)
 elseif(CMAKE_SYSTEM_NAME MATCHES "NetBSD")
   add_definitions(-DOS_NETBSD)
