--- src/test_tcp_port.c.orig	2024-02-02 01:02:32 UTC
+++ src/test_tcp_port.c
@@ -5,6 +5,7 @@
 #ifdef _WIN32
 #include <winsock2.h>
 #else
+#include <sys/socket.h>
 #include <netinet/in.h>
 #endif
 
