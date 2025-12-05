--- cmake/modules/LLDBConfig.cmake.orig	2025-12-01 12:58:50 UTC
+++ cmake/modules/LLDBConfig.cmake
@@ -309,7 +309,7 @@ endif()
 
 # Figure out if lldb could use lldb-server.  If so, then we'll
 # ensure we build lldb-server when an lldb target is being built.
-if (CMAKE_SYSTEM_NAME MATCHES "AIX|Android|Darwin|FreeBSD|Linux|NetBSD|OpenBSD|Windows")
+if (CMAKE_SYSTEM_NAME MATCHES "AIX|Android|Darwin|FreeBSD|Linux|NetBSD|OpenBSD|Windows|DragonFly|MidnightBSD")
   set(LLDB_CAN_USE_LLDB_SERVER ON)
 else()
   set(LLDB_CAN_USE_LLDB_SERVER OFF)
