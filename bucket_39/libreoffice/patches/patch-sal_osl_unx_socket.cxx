--- sal/osl/unx/socket.cxx.orig	2024-04-29 18:46:10 UTC
+++ sal/osl/unx/socket.cxx
@@ -39,6 +39,7 @@
 #include <arpa/inet.h>
 #include <fcntl.h>
 #include <netdb.h>
+#include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <poll.h>
 #include <unistd.h>
