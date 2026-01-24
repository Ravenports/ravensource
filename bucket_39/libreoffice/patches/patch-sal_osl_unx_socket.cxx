--- sal/osl/unx/socket.cxx.orig	2026-01-14 23:16:14 UTC
+++ sal/osl/unx/socket.cxx
@@ -39,9 +39,7 @@
 #include <arpa/inet.h>
 #include <fcntl.h>
 #include <netdb.h>
-#ifdef FREEBSD
 #include <netinet/ip.h>
-#endif
 #include <netinet/tcp.h>
 #include <poll.h>
 #include <unistd.h>
