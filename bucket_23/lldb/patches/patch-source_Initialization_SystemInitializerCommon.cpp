--- source/Initialization/SystemInitializerCommon.cpp.orig	2025-12-01 12:58:50 UTC
+++ source/Initialization/SystemInitializerCommon.cpp
@@ -19,6 +19,7 @@
 #include "lldb/Version/Version.h"
 
 #if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) ||       \
+    defined(__FreeBSD__) ||\
     defined(__OpenBSD__)
 #include "Plugins/Process/POSIX/ProcessPOSIXLog.h"
 #endif
@@ -79,6 +80,7 @@ llvm::Error SystemInitializerCommon::Ini
   process_gdb_remote::ProcessGDBRemoteLog::Initialize();
 
 #if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) ||       \
+    defined(__FreeBSD__) ||\
     defined(__OpenBSD__)
   ProcessPOSIXLog::Initialize();
 #endif
