--- gtk/DetailsDialog.cc.orig	2026-02-20 00:30:46 UTC
+++ gtk/DetailsDialog.cc
@@ -64,6 +64,8 @@
 #include <string_view>
 #include <unordered_map>
 
+#include <sys/socket.h>
+
 #ifdef _WIN32
 #include <winsock2.h>
 #include <ws2tcpip.h>
