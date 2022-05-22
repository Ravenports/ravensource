--- Source/WebCore/platform/network/DNS.h.orig	2022-02-23 11:41:50 UTC
+++ Source/WebCore/platform/network/DNS.h
@@ -34,6 +34,9 @@
 #include <ws2tcpip.h>
 #else
 #include <netinet/in.h>
+# if defined __DragonFly__ || defined __FreeBSD__ || defined __sun__
+#  include <sys/socket.h>
+# endif
 #endif
 
 namespace WebCore {
