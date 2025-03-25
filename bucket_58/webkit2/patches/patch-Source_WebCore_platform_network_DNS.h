--- Source/WebCore/platform/network/DNS.h.orig	2025-02-25 08:25:41 UTC
+++ Source/WebCore/platform/network/DNS.h
@@ -36,6 +36,9 @@
 #include <ws2tcpip.h>
 #else
 #include <netinet/in.h>
+# if defined __DragonFly__ || defined __FreeBSD__ || defined __sun__ || defined __MidnightBSD__
+#  include <sys/socket.h>
+# endif
 #endif
 
 namespace WebCore {
