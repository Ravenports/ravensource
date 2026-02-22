<strings.h> needed for bzero on omnios

--- contrib/sockets/sockets.lisp.orig	2024-05-10 11:13:55 UTC
+++ contrib/sockets/sockets.lisp
@@ -30,6 +30,7 @@
  "#include <sys/time.h>"
  "#include <netdb.h>"
  "#include <string.h>"
+ "#include <strings.h>"
  "#include <unistd.h>"
  "#include <netinet/in.h>"
  "#include <netinet/tcp.h>"
