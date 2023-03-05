--- gtk/DetailsDialog.cc.orig	2023-02-22 19:12:15 UTC
+++ gtk/DetailsDialog.cc
@@ -63,6 +63,8 @@
 #include <string_view>
 #include <unordered_map>
 
+#include <sys/socket.h>
+
 #ifdef _WIN32
 #include <winsock2.h>
 #include <ws2tcpip.h>
