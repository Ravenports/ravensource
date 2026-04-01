--- cmake/modules/LLDBConfig.cmake.orig	2026-03-23 18:46:22 UTC
+++ cmake/modules/LLDBConfig.cmake
@@ -354,7 +354,7 @@ endif()
 
 # Figure out if lldb could use lldb-server.  If so, then we'll
 # ensure we build lldb-server when an lldb target is being built.
-if (CMAKE_SYSTEM_NAME MATCHES "AIX|Android|Darwin|FreeBSD|Linux|NetBSD|OpenBSD|Windows")
+if (CMAKE_SYSTEM_NAME MATCHES "AIX|Android|Darwin|FreeBSD|Linux|NetBSD|OpenBSD|Windows|DragonFly|MidnightBSD")
   set(LLDB_CAN_USE_LLDB_SERVER ON)
 else()
   set(LLDB_CAN_USE_LLDB_SERVER OFF)
