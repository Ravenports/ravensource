--- sal/osl/unx/socket.cxx.orig	2025-01-12 19:04:12 UTC
+++ sal/osl/unx/socket.cxx
@@ -39,6 +39,7 @@
 #include <arpa/inet.h>
 #include <fcntl.h>
 #include <netdb.h>
+#include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <poll.h>
 #include <unistd.h>
