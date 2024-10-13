--- lib/socks_mosq.c.orig	2024-10-02 10:09:25 UTC
+++ lib/socks_mosq.c
@@ -30,7 +30,7 @@ Contributors:
 #else
 #  include <arpa/inet.h>
 #endif
-#if defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 #  include <sys/socket.h>
 #  include <netinet/in.h>
 #endif
