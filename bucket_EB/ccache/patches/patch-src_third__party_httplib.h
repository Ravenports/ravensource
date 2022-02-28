--- src/third_party/httplib.h.orig	2022-02-27 20:03:02 UTC
+++ src/third_party/httplib.h
@@ -169,7 +169,9 @@ using socket_t = SOCKET;
 
 #include <arpa/inet.h>
 #include <cstring>
+#ifndef __sun
 #include <ifaddrs.h>
+#endif
 #include <netdb.h>
 #include <netinet/in.h>
 #ifdef __linux__
