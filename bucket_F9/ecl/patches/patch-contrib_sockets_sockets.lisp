<strings.h> needed for bzero on omnios

--- contrib/sockets/sockets.lisp.orig	2026-05-05 09:20:39 UTC
+++ contrib/sockets/sockets.lisp
@@ -44,6 +44,7 @@
  "#include <sys/time.h>"
  "#include <netdb.h>"
  "#include <string.h>"
+ "#include <strings.h>"
  "#include <unistd.h>"
  "#include <netinet/in.h>"
  "#include <netinet/tcp.h>"
