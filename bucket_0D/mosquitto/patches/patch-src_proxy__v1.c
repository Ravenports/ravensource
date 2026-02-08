--- src/proxy_v1.c.orig	2026-02-04 22:33:13 UTC
+++ src/proxy_v1.c
@@ -2,6 +2,7 @@
 #  include <winsock2.h>
 #  include <ws2tcpip.h>
 #else
+#  include <netinet/in.h>
 #  include <arpa/inet.h>
 #endif
 #include <stdint.h>
