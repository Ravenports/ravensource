--- common/miscutil/network.c.orig	2025-01-15 18:11:59 UTC
+++ common/miscutil/network.c
@@ -39,6 +39,8 @@
 #include <errno.h>
 #include <unistd.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
+#include <sys/socket.h>
 #include <limits.h>             /* MAXHOSTNAMELEN */
 #ifdef HAVE_NETDB_H
 #include <netdb.h>              /* MAXHOSTNAMELEN Solaris */
