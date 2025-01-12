--- tools/lldb-server/lldb-gdbserver.cpp.orig	2024-12-17 11:04:04 UTC
+++ tools/lldb-server/lldb-gdbserver.cpp
@@ -39,7 +39,7 @@
 
 #if defined(__linux__)
 #include "Plugins/Process/Linux/NativeProcessLinux.h"
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #include "Plugins/Process/FreeBSD/NativeProcessFreeBSD.h"
 #elif defined(__NetBSD__)
 #include "Plugins/Process/NetBSD/NativeProcessNetBSD.h"
@@ -64,7 +64,7 @@ using namespace lldb_private::process_gd
 namespace {
 #if defined(__linux__)
 typedef process_linux::NativeProcessLinux::Manager NativeProcessManager;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 typedef process_freebsd::NativeProcessFreeBSD::Manager NativeProcessManager;
 #elif defined(__NetBSD__)
 typedef process_netbsd::NativeProcessNetBSD::Manager NativeProcessManager;
