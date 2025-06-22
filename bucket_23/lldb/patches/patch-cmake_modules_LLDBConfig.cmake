--- cmake/modules/LLDBConfig.cmake.orig	2025-06-13 04:54:32 UTC
+++ cmake/modules/LLDBConfig.cmake
@@ -292,7 +292,7 @@ endif()
 
 # Figure out if lldb could use lldb-server.  If so, then we'll
 # ensure we build lldb-server when an lldb target is being built.
-if (CMAKE_SYSTEM_NAME MATCHES "Android|Darwin|FreeBSD|Linux|NetBSD|OpenBSD|Windows")
+if (CMAKE_SYSTEM_NAME MATCHES "Android|Darwin|FreeBSD|Linux|NetBSD|OpenBSD|DragonFly|MidnightBSD|Windows")
   set(LLDB_CAN_USE_LLDB_SERVER ON)
 else()
   set(LLDB_CAN_USE_LLDB_SERVER OFF)
