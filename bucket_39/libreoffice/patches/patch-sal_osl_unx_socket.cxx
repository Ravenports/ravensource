--- sal/osl/unx/socket.cxx.orig	2026-04-09 16:07:27 UTC
+++ sal/osl/unx/socket.cxx
@@ -39,9 +39,8 @@
 #include <arpa/inet.h>
 #include <fcntl.h>
 #include <netdb.h>
-#ifdef FREEBSD
+#include <netinet/in.h>
 #include <netinet/ip.h>
-#endif
 #include <netinet/tcp.h>
 #include <poll.h>
 #include <unistd.h>
