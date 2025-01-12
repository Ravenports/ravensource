--- cmake/modules/LLDBConfig.cmake.orig	2024-12-17 11:04:04 UTC
+++ cmake/modules/LLDBConfig.cmake
@@ -299,7 +299,7 @@ endif()
 
 # Figure out if lldb could use lldb-server.  If so, then we'll
 # ensure we build lldb-server when an lldb target is being built.
-if (CMAKE_SYSTEM_NAME MATCHES "Android|Darwin|FreeBSD|Linux|NetBSD|Windows")
+if (CMAKE_SYSTEM_NAME MATCHES "Android|Darwin|FreeBSD|Linux|NetBSD|DragonFly|Windows")
   set(LLDB_CAN_USE_LLDB_SERVER ON)
 else()
   set(LLDB_CAN_USE_LLDB_SERVER OFF)
