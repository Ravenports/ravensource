--- tools/lldb-server/lldb-gdbserver.cpp.orig	2024-12-17 11:04:04 UTC
+++ tools/lldb-server/lldb-gdbserver.cpp
@@ -41,6 +41,8 @@
 #include "Plugins/Process/Linux/NativeProcessLinux.h"
 #elif defined(__FreeBSD__)
 #include "Plugins/Process/FreeBSD/NativeProcessFreeBSD.h"
+#elif defined(__DragonFly__)
+#include "Plugins/Process/DragonFly/NativeProcessDragonFly.h"
 #elif defined(__NetBSD__)
 #include "Plugins/Process/NetBSD/NativeProcessNetBSD.h"
 #elif defined(_WIN32)
@@ -66,6 +68,8 @@ namespace {
 typedef process_linux::NativeProcessLinux::Manager NativeProcessManager;
 #elif defined(__FreeBSD__)
 typedef process_freebsd::NativeProcessFreeBSD::Manager NativeProcessManager;
+#elif defined(__DragonFly__)
+typedef process_dragonfly::NativeProcessDragonFly::Manager NativeProcessManager;
 #elif defined(__NetBSD__)
 typedef process_netbsd::NativeProcessNetBSD::Manager NativeProcessManager;
 #elif defined(_WIN32)
