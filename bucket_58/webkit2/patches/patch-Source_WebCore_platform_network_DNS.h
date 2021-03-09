--- Source/WebCore/platform/network/DNS.h.orig	2020-08-12 09:17:55 UTC
+++ Source/WebCore/platform/network/DNS.h
@@ -30,6 +30,9 @@
 #include <ws2tcpip.h>
 #else
 #include <netinet/in.h>
+# if defined __DragonFly__ || defined __FreeBSD__ || defined __sun__
+#  include <sys/socket.h>
+# endif
 #endif
 
 #include <wtf/Forward.h>
